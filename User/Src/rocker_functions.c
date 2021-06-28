


#include "rocker_functions.h"

void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->ch1_x = *(adc_data + 0) * 3.3 / 4095;
    rocker_data->ch1_y = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->ch2_x = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->ch2_y = *(adc_data + 3) * 3.3 / 4095; 
}


void Rocker_Data_ADC2Control(__Control_Data* control_data,volatile uint16_t* adc_data)
{
    control_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[0]);// - offset_pitch;   
    control_data->roll     = 2000 - (uint16_t)(0.25f * adc_data[1]);// - offset_roll;
    control_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[2]);// - offset_throttle;
    control_data->yaw      = 1000 + (uint16_t)(0.25f * adc_data[3]);// - offset_yaw;

    Rocker_Data_Limit(control_data);
}


void Rocker_Data_Limit(__Control_Data* control_data)
{
    control_data->yaw = (control_data->yaw <= 1000)? 1000:control_data->yaw;
    control_data->yaw = (control_data->yaw >= 2000)? 2000:control_data->yaw;

    control_data->roll = (control_data->roll <= 1000)? 1000:control_data->roll;
    control_data->roll = (control_data->roll >= 2000)? 2000:control_data->roll;
    control_data->pitch = (control_data->pitch <= 1000)? 1000:control_data->pitch;
    control_data->pitch = (control_data->pitch >= 2000)? 2000:control_data->pitch;

    control_data->throttle = (control_data->throttle <= 1000)? 1000:control_data->throttle;
    control_data->throttle = (control_data->throttle >= 2000)? 2000:control_data->throttle;

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