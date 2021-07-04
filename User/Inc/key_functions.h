/**
  ******************************************************************************
  * @file    key_function.h
  * @brief   This is a header file for key_function.
  *          It used to handle what we do after the key is entered.
  *
  * 
  * 
  ******************************************************************************
  */



 #ifndef __KEY_FUNCTION_H
 #define __KEY_FUNCTION_H
 
 #include "stm32f4xx.h"
 #include "rc_struct.h"

 uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

 void Key_Data_Write(uint16_t* GPIO_Pin,__Key_Data* data);


 #endif