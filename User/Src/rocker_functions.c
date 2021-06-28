


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
    control_data->pitch    = adc_data[0] * 0.02 - 45;   //-45 ~ 45
    control_data->roll     = adc_data[1] * 0.02 - 45;   //-45 ~ 45
    control_data->throttle = adc_data[2] * 0.0005 - 1;  //-1  ~ 1
    control_data->yaw      = adc_data[3] * 0.0005 - 1;  //-1  ~ 1
}
