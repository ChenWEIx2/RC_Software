/**
  ******************************************************************************
  * @file    bsp_led.h
  * @brief   This is a header file for BSP_LED
  *          LED_XXX_ON:     Turn on LED
  *          LED_XXX_OFF:    Turn off LED
  *          LED_XXX_Toggle: Change the current state of led_xxx
  ******************************************************************************
  */


 #ifndef __LED_FUNCTIONS_H
 #define __LED_FUNCTIONS_H

 #include "stm32f4xx.h"
 #include "main.h"


 #define LED_Green_ON      HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
 #define LED_Green_OFF     HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
 #define LED_Green_Toggle  HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);

 #define LED_Red_ON        HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
 #define LED_Red_OFF       HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
 #define LED_Red_Toggle    HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);




 #endif