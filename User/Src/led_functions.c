/**
  ******************************************************************************
  * @file    bsp_led.c
  * @brief   This is a source file for BSP_LED
  ******************************************************************************
  */


 #include "led_functions.h"

 void LED_GPIO_Init(void){
    GPIO_InitTypeDef LED_GPIO_Init_TypeDef;
     __HAL_RCC_GPIOB_CLK_ENABLE();

    LED_GPIO_Init_TypeDef.Mode  = GPIO_MODE_OUTPUT_PP;
    LED_GPIO_Init_TypeDef.Pin   = GPIO_PIN_9 | GPIO_PIN_10;
    LED_GPIO_Init_TypeDef.Pull  = GPIO_NOPULL;
    LED_GPIO_Init_TypeDef.Speed = GPIO_SPEED_FREQ_LOW;

     HAL_GPIO_Init(GPIOB,&LED_GPIO_Init_TypeDef);

 }
 
