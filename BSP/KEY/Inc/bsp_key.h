/**
  ******************************************************************************
  * @file    bsp_key.h
  * @brief   This is a header file for BSP_KEY
  *          
  ******************************************************************************
  */




 #ifndef __BSP_KEY_H
 #define __BSP_KEY_H

 #include "stm32f4xx.h"

 void KEY_GPIO_Init(void);

 uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);


 #endif
