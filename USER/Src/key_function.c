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


 void Key_FSM(GPIO_TypeDef* GPIOx,uint16_t* GPIO_Pin){
     
     if(Key_Scan(GPIOx, *GPIO_Pin))  Key_0();
     if(Key_Scan(GPIOx, *(GPIO_Pin + 1))) Key_1();
     if(Key_Scan(GPIOx, *(GPIO_Pin + 2))) Key_2();
     if(Key_Scan(GPIOx, *(GPIO_Pin + 3))) Key_3();
     if(Key_Scan(GPIOx, *(GPIO_Pin + 4))) Key_4();
     if(Key_Scan(GPIOx, *(GPIO_Pin + 5))) Key_5();
 }
