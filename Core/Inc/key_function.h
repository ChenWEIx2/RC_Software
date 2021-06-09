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
 #include "bsp_key.h"
 #include "rc_struct.h"

 void Key_FSM(GPIO_TypeDef* GPIOx,uint16_t* GPIO_Pin,__key_data data);


 #endif