

#include "beep_functions.h"

void Beep_Toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,uint16_t Frequency)
{
    uint8_t count = 10;
    while(count)
    {
        HAL_GPIO_TogglePin(GPIOx,GPIO_Pin);
        HAL_Delay(1000/Frequency);
        count--; 
    }
}