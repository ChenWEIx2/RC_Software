



#ifndef __ROCKER_FUNCTIONS_H
#define __ROCKER_FUNCTIONS_H

#include "rc_struct.h"
#include "log.h"


void Rocker_Data_Mapping(__Rocker_Data* rocker_data,volatile uint16_t* adc_data);

void Rocker_Data_Log(__Rocker_Data* rocker_data,uint8_t n);

void float2char(float slope,char*buffer,int n);

#endif