#ifndef __RC_FUNCTIONS_H
#define __RC_FUNCTIONS_H

#include "beep_functions.h"
#include "rc_struct.h"
#include "log.h"



void Rocker_Data_ADC2Voltage(__RC_Data* rc_data,volatile uint16_t* adc_data);

void Rocker_Data_ADC2Control(__RC_Data* rc_data,volatile uint16_t* adc_data);

void Rocker_Data_Limit(__RC_Data* rc_data);

uint8_t Unlock_Flag(volatile uint16_t* adc_result);

uint8_t Offset_Flag(volatile uint16_t* adc_result);

void Do_Offset();

#endif