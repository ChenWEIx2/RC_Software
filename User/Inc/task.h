


#ifndef __TASK_H
#define __TASK_H

#include "rc_struct.h"
#include "key_functions.h"
#include "rc_functions.h"

void Task_500Hz(__RC_Data* rc_data,volatile uint16_t* adc_result,uint16_t* Key_Pin,__Key_Data* key_data);
void Task_100Hz();
void Task_025Hz();

#endif