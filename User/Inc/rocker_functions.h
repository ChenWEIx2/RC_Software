



#ifndef __ROCKER_FUNCTIONS_H
#define __ROCKER_FUNCTIONS_H

#include "rc_struct.h"
#include "log.h"


void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data);

void Rocker_Data_ADC2Control(__Control_Data* control_data,volatile uint16_t* adc_data);


#endif