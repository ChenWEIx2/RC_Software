#include "rc_functions.h"

void Rocker_Data_ADC2Voltage(__RC_Data* rc_data,volatile uint16_t* adc_data)
{
    rc_data->pitch = *(adc_data + 0) * 3.3 / 4095;
    rc_data->roll = *(adc_data + 1) * 3.3 / 4095;
    rc_data->throttle = *(adc_data + 2) * 3.3 / 4095;
    rc_data->yaw = *(adc_data + 3) * 3.3 / 4095; 
}


void Rocker_Data_ADC2rc(__RC_Data* rc_data,volatile uint16_t* adc_data)
{
    rc_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[0]);// - offset_pitch;   
    rc_data->roll     = 2000 - (uint16_t)(0.25f * adc_data[1]);// - offset_roll;
    rc_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[2]);// - offset_throttle;
    rc_data->yaw      = 1000 + (uint16_t)(0.25f * adc_data[3]);// - offset_yaw;

    Rocker_Data_Limit(rc_data);
}


void Rocker_Data_Limit(__RC_Data* rc_data)
{
    rc_data->yaw = (rc_data->yaw <= 1000)? 1000:rc_data->yaw;
    rc_data->yaw = (rc_data->yaw >= 2000)? 2000:rc_data->yaw;

    rc_data->roll = (rc_data->roll <= 1000)? 1000:rc_data->roll;
    rc_data->roll = (rc_data->roll >= 2000)? 2000:rc_data->roll;
    rc_data->pitch = (rc_data->pitch <= 1000)? 1000:rc_data->pitch;
    rc_data->pitch = (rc_data->pitch >= 2000)? 2000:rc_data->pitch;

    rc_data->throttle = (rc_data->throttle <= 1000)? 1000:rc_data->throttle;
    rc_data->throttle = (rc_data->throttle >= 2000)? 2000:rc_data->throttle;

}



uint8_t Unlock_Flag(volatile uint16_t* adc_result)
{
    uint8_t flag = (adc_result[0]>4000) && (adc_result[1]<4000) && (adc_result[2]>4000) && (adc_result[3]>4000);
    return flag;
}

uint8_t Offset_Flag(volatile uint16_t* adc_result)
{
    uint8_t flag = (adc_result[0]>4000) && (adc_result[1]>4000) && (adc_result[2]>4000) && (adc_result[3]<4000);
    return flag;

}