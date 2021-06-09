/**
  ******************************************************************************
  * @file    bsp_key.c
  * @brief   This is a source file for BSP_KEY
  *          
  ******************************************************************************
  */



 #include "bsp_key.h"

 void KEY_GPIO_Init(void){
     GPIO_InitTypeDef  KEY_GPIO_Init_TypeDef;

     __HAL_RCC_GPIOB_CLK_ENABLE();

     KEY_GPIO_Init_TypeDef.Mode  = GPIO_MODE_INPUT;
     KEY_GPIO_Init_TypeDef.Pin   = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
     KEY_GPIO_Init_TypeDef.Pull  = GPIO_NOPULL;
     KEY_GPIO_Init_TypeDef.Speed = GPIO_SPEED_FREQ_LOW;

     HAL_GPIO_Init(GPIOB,&KEY_GPIO_Init_TypeDef);  

 }


  uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin){
    
    /*judege the key was entered or not*/
    if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_RESET){
        /* Entered */
        while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_SET);
        return 1;
    }
    else{
        /* Did not Enter */
        return 0;
    }
 }