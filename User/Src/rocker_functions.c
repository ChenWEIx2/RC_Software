


#include "rocker_functions.h"

void Rocker_Data_Mapping(__Rocker_Data* rocker_data,volatile uint16_t* adc_data)
{
    rocker_data->ch1_x = *adc_data * 3.3 / 4095;
    rocker_data->ch1_y = *(adc_data + 1) * 3.3 / 4095;
    rocker_data->ch2_x = *(adc_data + 2) * 3.3 / 4095;
    rocker_data->ch2_y = *(adc_data + 3) * 3.3 / 4095; 
}