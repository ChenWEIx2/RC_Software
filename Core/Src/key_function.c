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


 void Key_FSM(GPIO_TypeDef* GPIOx,uint16_t* GPIO_Pin,__key_data data){
     
     data.key_0 &= 0;
     data.key_1 &= 0;
     data.key_2 &= 0;
     data.key_3 &= 0; 
     data.key_4 &= 0;
     data.key_5 &= 0;  
 
     if(Key_Scan(GPIOx, *GPIO_Pin))  data.key_0 = 1;
     if(Key_Scan(GPIOx, *(GPIO_Pin + 1))) data.key_1 = 1;
     if(Key_Scan(GPIOx, *(GPIO_Pin + 2))) data.key_2 = 1;
     if(Key_Scan(GPIOx, *(GPIO_Pin + 3))) data.key_3 = 1;
     if(Key_Scan(GPIOx, *(GPIO_Pin + 4))) data.key_4 = 1;
     if(Key_Scan(GPIOx, *(GPIO_Pin + 5))) data.key_5 = 5;
 
 }
