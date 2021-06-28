


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
    rocker_data->pitch    = adc_data[0] * 0.02 - 45;   //-45 ~ 45
    rocker_data->roll     = adc_data[1] * 0.02 - 45;   //-45 ~ 45
    rocker_data->throttle = adc_data[2] * 0.0005 - 1;  //-1  ~ 1
    rocker_data->yaw      = adc_data[3] * 0.0005 - 1;  //-1  ~ 1
}
