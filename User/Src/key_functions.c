/**
  ******************************************************************************
  * @file    key_function.c
  * @brief   This is a source file for key_function.
  *          Key_FSM: handle all keys detection and enter keys function
  *
  * 
  ******************************************************************************
  */


 
 #include "key_functions.h"
 #include "led_functions.h"



uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
    if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_RESET)
        {
            while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_RESET);
        }
        return 1;
    }
        
    return 0;
 }

 void Key_Data_Write(uint16_t* GPIO_Pin,__Key_Data* data){
     
    data->front_fine_tune_Key = (Key_Scan(GPIOB, *GPIO_Pin));
    data->back_fine_tune_key = (Key_Scan(GPIOA, *(GPIO_Pin + 1)));
    data->left_fine_tune_key = (Key_Scan(GPIOB, *(GPIO_Pin + 2)));
    data->right_fine_tune_key = (Key_Scan(GPIOB, *(GPIO_Pin + 3))); 
    data->left_key = (Key_Scan(GPIOA, *(GPIO_Pin + 4)));
    data->right_key = (Key_Scan(GPIOA, *(GPIO_Pin + 5)));  
 
 }
