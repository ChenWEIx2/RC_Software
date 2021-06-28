


#include "task.h"


void Task_500Hz(__RC_Data* rc_data,volatile uint16_t* adc_result,uint16_t* Key_Pin,__Key_Data* key_data)
{
    Rocker_Data_ADC2Control(rc_data,adc_result);
    Key_Data_Write(GPIOB,Key_Pin,key_data);
}