

#ifndef __UNLOKC_H
#define __UNLOCK_H

#include "main.h"
#include "beep_functions.h"

uint8_t Unlock_Flag(volatile uint16_t* adc_result);

uint8_t Offset_Flag(volatile uint16_t* adc_result);

void Do_Offset();


#endif