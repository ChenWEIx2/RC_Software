


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
    control_data->pitch    = 1000 + (uint16_t)(0.25f * adc_data[0]) - offset_pitch;   
    control_data->roll     = 2000 - (uint16_t)(0.25f * adc_data[1]) - offset_roll;
    control_data->throttle = 2000 - (uint16_t)(0.25f * adc_data[2]) - offset_throttle;
    control_data->yaw      = 1000 + (uint16_t)(0.25f * adc_data[3]) - offset_yaw;
}
