/**
  ******************************************************************************
  * @file    key_function.c
  * @brief   This is a source file for key_function.
  *          Key_FSM: handle all keys detection and enter keys function
  *
  * 
  ******************************************************************************
  */


 
 #include "key_functions.h"


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

 void Key_Data_Write(GPIO_TypeDef* GPIOx,uint16_t* GPIO_Pin,__Key_Data* data){
     
    data->key_0 = (Key_Scan(GPIOx, *GPIO_Pin))? 1:0;
    data->key_1 = (Key_Scan(GPIOx, *(GPIO_Pin + 1)))? 1:0;
    data->key_2 = (Key_Scan(GPIOx, *(GPIO_Pin + 2)))? 1:0;
    data->key_3 = (Key_Scan(GPIOx, *(GPIO_Pin + 3)))? 1:0; 
    data->key_4 = (Key_Scan(GPIOx, *(GPIO_Pin + 4)))? 1:0;
    data->key_5 = (Key_Scan(GPIOx, *(GPIO_Pin + 5)))? 1:0;  
 
 }
