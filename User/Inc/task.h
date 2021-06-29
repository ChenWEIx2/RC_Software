#ifndef __TASK_H
#define __TASK_H

#include "stdio.h"
#include "usart.h"
#include "rc_struct.h"


void Task_500Hz();

void Task_100Hz();

void Task_25Hz(__Key_Data key_data,__Rocker_Data rocker_data);

#endif