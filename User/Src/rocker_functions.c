


#include "rocker_functions.h"

void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->pitch = *(adc_data + 0) * 3.3 / 4095;
    rocker_data->roll = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->throttle = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->yaw = *(adc_data + 3) * 3.3 / 4095; 
}


void Rocker_Data_ADC2Control(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[0]);// - offset_pitch;   
    rocker_data->roll     = 2000 - (uint16_t)(0.25f * adc_data[1]);// - offset_roll;
    rocker_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[2]);// - offset_throttle;
    rocker_data->yaw      = 1000 + (uint16_t)(0.25f * adc_data[3]);// - offset_yaw;
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