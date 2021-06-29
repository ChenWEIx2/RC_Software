#ifndef __TASK_H
#define __TASK_H

#include "stdio.h"
#include "usart.h"
#include "rc_struct.h"
#include "rocker_functions.h"
#include "beep_functions.h"
#include "key_functions.h"


void Task_500Hz(__Rocker_Data* rocker_data,volatile uint16_t* adc_result,__Key_Data* key_data,uint16_t* key_Pin,__Start__Flag* start_flag,uint16_t* offset_data);

void Task_100Hz();

void Task_25Hz(__Key_Data key_data,__Rocker_Data rocker_data);

#endif