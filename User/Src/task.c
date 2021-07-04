#include "task.h"


void Task_25Hz(__Key_Data key_data,__Rocker_Data rocker_data)
{
    //printf("Key status:%d, %d, %d, %d, %d, %d.\r\n",key_data.key_0,key_data.key_1,key_data.key_2,key_data.key_3,key_data.key_4,key_data.key_5);
    printf("Pitch=%d.\r\n",rocker_data.pitch);
    printf("Roll=%d.\r\n",rocker_data.roll);
    printf("Throttle=%d.\r\n",rocker_data.throttle);
    printf("Yaw=%d.\r\n",rocker_data.yaw);
}


void Task_100Hz(__Rocker_Data rocker_data,__Key_Data key_data)
{
    uint8_t nrf24l01_tx_buff[33];
    uint8_t nrf24l01_flag = 0;
    uint8_t nrf24l01_check_count = 0;
        
    nrf24l01_tx_buff[0] = key_data.front_fine_tune_Key;
    nrf24l01_tx_buff[1] = key_data.back_fine_tune_key;
    nrf24l01_tx_buff[2] = key_data.left_fine_tune_key;
    nrf24l01_tx_buff[3] = key_data.right_fine_tune_key;
    nrf24l01_tx_buff[4] = key_data.left_key;
    nrf24l01_tx_buff[5] = key_data.right_key;

    nrf24l01_tx_buff[6] = (uint8_t) (rocker_data.pitch * 0.01);       //Thousand digit + Hundered digit
    nrf24l01_tx_buff[7] = (uint8_t) (rocker_data.pitch % 100);        //Ten digit + Seat digit 

    nrf24l01_tx_buff[8] = (uint8_t) (rocker_data.roll * 0.01);        //Thousand digit + Hundered digit
    nrf24l01_tx_buff[9] = (uint8_t) (rocker_data.roll % 100);         //Ten digit + Seat digit
    
    nrf24l01_tx_buff[10] = (uint8_t) (rocker_data.throttle * 0.01);   //Thousand digit + Hundered digit 
    nrf24l01_tx_buff[11] = (uint8_t) (rocker_data.throttle % 100);    //Ten digit + Seat digit

    nrf24l01_tx_buff[12] = (uint8_t) (rocker_data.yaw * 0.01);        //Thousand digit + Hundered digit
    nrf24l01_tx_buff[13] = (uint8_t) (rocker_data.yaw % 100);         //Ten digit + Seat digit

    while(nrf24l01_check_count++ < 11)                 //Check nrf24l01
	{
        if(NRF24L01_Check())
        {
            nrf24l01_flag = 1;
            NRF24L01_TX_Mode();
            printf("NRF24L01 enter TX mode.\r\n");
            break;
        }
        else
        {
            printf("Can not find nrf24l01!!!\r\n");
            nrf24l01_flag = 0;
		    HAL_Delay(1000);
        }
	}

    if(nrf24l01_flag && (NRF24L01_TxPacket(nrf24l01_tx_buff)==TX_OK))
    {
      printf("Tx success.\r\n");
      LED_Green_ON;
    }
    else
    {
      printf("TX error!!!\r\n");
      LED_Green_OFF;
    } 
 
}


void Task_500Hz(__Rocker_Data* rocker_data,volatile uint16_t* adc_result,__Key_Data* key_data,uint16_t* key_Pin,__Start__Flag* start_flag,int16_t* offset_data)
{
    //Get key and rocker data;
    Key_Data_Write(key_Pin,key_data);
    Rocker_Data_ADC2Control(rocker_data,adc_result,offset_data,start_flag->offset_finish_flag);
    
    //unlock
    if(!start_flag->unlock_finish_flag)
    {
        if(Unlock_Flag(*rocker_data)) start_flag->unlock_counter +=1;

        if(start_flag->unlock_counter >= 50)  //1s
        {
            start_flag->unlock_finish_flag = 1;
            start_flag->unlock_counter = 0;

            //FLASH_READ_SECTOR5(offset_data,4);
            UNLOCK_BEEP;
            printf("Offset data:%d,%d,%d,%d\r\n",offset_data[0],offset_data[1],offset_data[2],offset_data[3]);
        }
    }
    
    //offset planA
    /*
    if(Offset_Flag(*key_data) && (!start_flag->offset_finish_flag))
    {
        start_flag->offset_finish_flag = 0;
        start_flag->offset_counter = (start_flag->offset_counter > 501)? 501:(start_flag->offset_counter + 1);

        if(start_flag->offset_counter == 50) UNLOCK_BEEP;  //begin to do offset

        if(start_flag->offset_counter >= 50) //1s
        {
            start_flag->offset_finish_flag = Do_Offset(*rocker_data,offset_data,&(start_flag->do_offset_counter));            
        }

        if(start_flag->offset_finish_flag)    //end do offset
        {
            //FLASH_WRITE_SECTOR5(offset_data,4);
            LED_Green_ON;
            //UNLOCK_BEEP; 
        } 
    }
    */

   //offset planB
    if(!start_flag->offset_finish_flag && !start_flag->unlock_finish_flag)
    {
        if(rocker_data->throttle < 1100) start_flag->right_offset_counter += 1;
        if(rocker_data->pitch < 1100) start_flag->left_offset_counter += 1;

        if(start_flag->right_offset_counter >= 50 && !(start_flag->right_offset_finish_flag))  //1s
        {
            start_flag->right_offset_finish_flag = Do_Right_Offset(rocker_data,offset_data,&(start_flag->do_right_offset_counter));
            printf("Right Offset now \r\n");
            UNLOCK_BEEP;
        }
 
        //1s + right do not finish + left finish
        if(start_flag->left_offset_counter >= 50 && (start_flag->right_offset_finish_flag) && !(start_flag->left_offset_finish_flag))
        {
            start_flag->left_offset_finish_flag = Do_Left_Offset(rocker_data,offset_data,&(start_flag->do_left_offset_counter));
            printf("Left Offset now \r\n");
            UNLOCK_BEEP;
        }

        start_flag->offset_finish_flag = start_flag->right_offset_finish_flag & start_flag->left_offset_finish_flag;
        if(start_flag->offset_finish_flag)
        {
            uint16_t offset_temp[8];
            for(uint8_t i=0 ;i<4; i++)
            {
                offset_temp[i] = abs(offset_data[i]);
                offset_temp[i+4] = (offset_data[i] > 0)? 2:0;
            }
            FLASH_WRITE_SECTOR5(offset_temp,8);
        }
        
        printf("Offset:%d,%d,%d,%d\r\n",offset_data[0],offset_data[1],offset_data[2],offset_data[3]);
        printf("do offset count:%d,%d\r\n",start_flag->do_right_offset_counter,start_flag->do_left_offset_counter);


    }

    
    
}

