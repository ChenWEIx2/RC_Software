



#ifndef __ROCKER_FUNCTIONS_H
#define __ROCKER_FUNCTIONS_H

#include "rc_struct.h"
#include "log.h"


void Rocker_Data_ADC2Voltage(__Rocker_Data* rocker_data,volatile uint16_t* adc_data);

void Rocker_Data_ADC2Control(__Rocker_Data* rocker_data,volatile uint16_t* adc_data,uint16_t* offset_data,uint8_t offset_finish_flag);

void Rocker_Data_Limit(__Rocker_Data* rocker_data);

uint8_t Do_Offset(__Rocker_Data rocker_data,uint16_t* offset_data,uint8_t* count);

uint8_t Unlock_Flag(__Rocker_Data rocker_data);

uint8_t Offset_Flag(__Rocker_Data rocker_data);


#endif