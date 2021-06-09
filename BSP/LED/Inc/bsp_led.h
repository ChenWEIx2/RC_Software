/**
  ******************************************************************************
  * @file    bsp_led.h
  * @brief   This is a header file for BSP_LED
  *          LED_XXX_ON:     Turn on LED
  *          LED_XXX_OFF:    Turn off LED
  *          LED_XXX_Toggle: Change the current state of led_xxx
  ******************************************************************************
  */


 #ifndef __BSP_LED_H
 #define __BSP_LED_H

 #include "stm32f4xx.h"

 #define LED_Green_ON      do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);}while(0)
 #define LED_Green_OFF     do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RSET);}while(0)
 #define LED_Green_Toggle  do{HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);}while(0)

 #define LED_Red_ON        do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);}while(0)
 #define LED_Red_OFF       do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RSET);}while(0)
 #define LED_Red_Toggle    do{HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_10);}while(0)



 //Init the GPIO of LED
 void LED_GPIO_Init(void);


 #endif