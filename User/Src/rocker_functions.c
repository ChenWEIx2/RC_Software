


#include "rocker_functions.h"

void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->pitch = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->roll = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->throttle = *(adc_data + 3) * 3.3 / 4095;
    rocker_data->yaw = *(adc_data + 4) * 3.3 / 4095; 
}


void Rocker_Data_ADC2Control(__Rocker_Data* rocker_data,volatile uint16_t* adc_data,int16_t* offset_data,uint8_t offset_finish_flag)
{
    rocker_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[2]) + offset_data[0] * offset_finish_flag;   
    rocker_data->roll     = 1000 + (uint16_t)(0.25f * adc_data[1]) + offset_data[1] * offset_finish_flag;
    rocker_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[3]) + offset_data[2] * offset_finish_flag;
    rocker_data->yaw      = 2000 - (uint16_t)(0.25f * adc_data[4]) + offset_data[3] * offset_finish_flag;

    Rocker_Data_Limit(rocker_data);
}


void Rocker_Data_Limit(__Rocker_Data* rocker_data)
{
    rocker_data->yaw = (rocker_data->yaw <= 1000)? 1000:rocker_data->yaw;
    rocker_data->yaw = (rocker_data->yaw >= 2000)? 2000:rocker_data->yaw;

    rocker_data->roll = (rocker_data->roll <= 1000)? 1000:rocker_data->roll;
    rocker_data->roll = (rocker_data->roll >= 2000)? 2000:rocker_data->roll;

    rocker_data->pitch = (rocker_data->pitch <= 1000)? 1000:rocker_data->pitch;
    rocker_data->pitch = (rocker_data->pitch >= 2000)? 2000:rocker_data->pitch;

    rocker_data->throttle = (rocker_data->throttle <= 1000)? 1000:rocker_data->throttle;
    rocker_data->throttle = (rocker_data->throttle >= 2000)? 2000:rocker_data->throttle;
}


uint8_t Do_Left_Offset(__Rocker_Data* rocker_data,int16_t* offset_data,uint8_t* count)
{
    if(*count==0)
    {
        offset_data[2] = 0;
        offset_data[3] = 0;

        (*count)++;
    }
    else
    {
        offset_data[2] += (1500 - rocker_data->throttle);
        offset_data[3] += (1500 - rocker_data->yaw);
    
        (*count)++;
    }

    if(*count == 50)
    {
        offset_data[2] = (int16_t) (offset_data[2]/50);
        offset_data[3] = (int16_t) (offset_data[3]/50);

        return 1;
    }
    return 0;
}

uint8_t Do_Right_Offset(__Rocker_Data* rocker_data,int16_t* offset_data,uint8_t* count)
{
    if(*count==0)
    {
        offset_data[0] = 0;
        offset_data[1] = 0;

        (*count)++;
    }
    else
    {
        offset_data[0] += (1500 - rocker_data->pitch);
        offset_data[1] += (1500 - rocker_data->roll);

        (*count)++;
    }

    if(*count == 50)
    {
        offset_data[0] = (int16_t) (offset_data[0]/50);
        offset_data[1] = (int16_t) (offset_data[1]/50);

        return 1;
    }
    return 0;
}

uint8_t Unlock_Flag(__Rocker_Data rocker_data)
{
    uint8_t flag = (rocker_data.pitch > 1800.0) &
                   (rocker_data.throttle > 1800.0);
    return flag;
}

//Offset Plan A
/*
uint8_t Offset_Flag(__Key_Data key_data)
{
    uint8_t flag = key_data.left_key &
                   key_data.right_key;
    return flag;   
}
*/
