


#include "rocker_functions.h"

void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->pitch = *(adc_data + 0) * 3.3 / 4095;
    rocker_data->roll = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->throttle = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->yaw = *(adc_data + 3) * 3.3 / 4095; 
}


void Rocker_Data_ADC2Control(__Rocker_Data* rocker_data,volatile uint16_t* adc_data,uint16_t* offset_data,uint8_t offset_finish_flag)
{
    rocker_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[2]) - offset_data[0] * offset_finish_flag;   
    rocker_data->roll     = 1000 + (uint16_t)(0.25f * adc_data[1]) - offset_data[1] * offset_finish_flag;
    rocker_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[3]) - offset_data[2] * offset_finish_flag;
    rocker_data->yaw      = 2000 - (uint16_t)(0.25f * adc_data[4]) - offset_data[3] * offset_finish_flag;

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


uint8_t Do_Offset(__Rocker_Data rocker_data,uint16_t* offset_data,uint8_t* count)
{
    if(*count==0)
    {
        offset_data[0] = 0;
        offset_data[1] = 0;
        offset_data[2] = 0;
        offset_data[3] = 0;

        (*count)++;
    }
    else
    {
        offset_data[0] += rocker_data.pitch;
        offset_data[1] += rocker_data.roll;
        offset_data[2] += rocker_data.throttle;
        offset_data[3] += rocker_data.yaw;

        (*count)++;
    }

    if(*count >=50)
    {
        (*count)--;

        offset_data[0] = (uint16_t) (offset_data[0]/(*count));
        offset_data[1] = (uint16_t) (offset_data[1]/(*count));
        offset_data[2] = (uint16_t) (offset_data[2]/(*count));
        offset_data[3] = (uint16_t) (offset_data[3]/(*count));

        return 1;
    }
    return 0;
}


uint8_t Unlock_Flag(__Rocker_Data rocker_data)
{
    uint8_t flag = (rocker_data.pitch > 1800.0) &
                   (rocker_data.roll > 1800.0) &
                   (rocker_data.throttle > 1800.0) &
                   (rocker_data.yaw > 1800.0);
    return flag;
}


uint8_t Offset_Flag(__Key_Data key_data)
{
    uint8_t flag = key_data.key_0 &
                   key_data.key_1 &
                   key_data.key_2 &
                   key_data.key_3;
    return flag;   
}