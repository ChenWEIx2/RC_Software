

#ifndef __BEEP_FUNCTIONS_H
#define __BEEP_FUNCTIONS_H

#include "stm32f4xx.h"
#include "main.h"

#define POWER_ON_BEEP Beep_Toggle(Beep_GPIO_Port,Beep_Pin,1000);
#define UNLOCK_OR_OFFSET_BEEP Beep_Toggle(Beep_GPIO_Port,Beep_Pin,2000);


void Beep_Toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,uint16_t Frequency);

#endif