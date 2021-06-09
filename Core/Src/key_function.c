/**
  ******************************************************************************
  * @file    key_function.c
  * @brief   This is a source file for key_function.
  *          Key_FSM: handle all keys detection and enter keys function
  *
  * 
  ******************************************************************************
  */


 
 #include "key_function.h"


 void Key_Data_Write(GPIO_TypeDef* GPIOx,uint16_t* GPIO_Pin,__key_data* data){
     
    data->key_0 = (Key_Scan(GPIOx, *GPIO_Pin))? 1:0;
    data->key_1 = (Key_Scan(GPIOx, *(GPIO_Pin + 1)))? 1:0;
    data->key_2 = (Key_Scan(GPIOx, *(GPIO_Pin + 2)))? 1:0;
    data->key_3 = (Key_Scan(GPIOx, *(GPIO_Pin + 3)))? 1:0; 
    data->key_4 = (Key_Scan(GPIOx, *(GPIO_Pin + 4)))? 1:0;
    data->key_5 = (Key_Scan(GPIOx, *(GPIO_Pin + 5)))? 1:0;  
 
 }
