#include "task.h"


void Task_25Hz(__Key_Data key_data,__Rocker_Data rocker_data)
{
    printf("Key status:%d, %d, %d, %d, %d, %d.\r\n",key_data.key_0,key_data.key_1,key_data.key_2,key_data.key_3,key_data.key_4,key_data.key_5);
    printf("Pitch:%d.\r\n",rocker_data.pitch);
    printf("Roll:%d.\r\n",rocker_data.roll);
    printf("Throttle:%d.\r\n",rocker_data.throttle);
    printf("Yaw:%d.\r\n",rocker_data.yaw);
}


void Task_500Hz(__Rocker_Data* rocker_data,volatile uint16_t* adc_result,__Key_Data* key_data,uint16_t* key_Pin,__Start__Flag* start_flag,uint16_t* offset_data)
{
    //Get key and rocker data;
    Key_Data_Write(GPIOB,key_Pin,key_data);
    Rocker_Data_ADC2Control(rocker_data,adc_result,offset_data,start_flag->offset_finish_flag);

    //unlock
    if(!start_flag->unlock_finish_flag)
    {        
        if(Unlock_Flag(*rocker_data)) start_flag->unlock_counter +=1;

        if(start_flag->unlock_counter >= 500)  //1s
        {
            start_flag->offset_finish_flag = 1;
            start_flag->unlock_finish_flag = 1;
            start_flag->unlock_counter = 0;
        }
    }
    
    //offset
    if(!start_flag->offset_finish_flag)
    {
        if(Offset_Flag(*rocker_data)) start_flag->offset_counter +=1;

        if(start_flag->offset_counter >= 500) //1s
        {
            start_flag->offset_finish_flag = 1;
            start_flag->offset_counter = 0;
            //do offset
            //Do_Offset(*rocker_data,offset_data,start_flag->do_offset_counter);
        }
    }
    
}

