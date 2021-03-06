/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rc_struct.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Back_Fine_Tune_Key_Pin GPIO_PIN_7
#define Back_Fine_Tune_Key_GPIO_Port GPIOA
#define Front_Fine_Tune_Key_Pin GPIO_PIN_0
#define Front_Fine_Tune_Key_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define NRF24L01_CE_Pin GPIO_PIN_10
#define NRF24L01_CE_GPIO_Port GPIOB
#define NRF24L01_CS_Pin GPIO_PIN_12
#define NRF24L01_CS_GPIO_Port GPIOB
#define NRF24L01_SPI_SCK_Pin GPIO_PIN_13
#define NRF24L01_SPI_SCK_GPIO_Port GPIOB
#define NRF24L01_SPI_MISO_Pin GPIO_PIN_14
#define NRF24L01_SPI_MISO_GPIO_Port GPIOB
#define NRF24L01_SPI_MOSI_Pin GPIO_PIN_15
#define NRF24L01_SPI_MOSI_GPIO_Port GPIOB
#define NRF24L01_IRQ_Pin GPIO_PIN_8
#define NRF24L01_IRQ_GPIO_Port GPIOA
#define Left_Key_Pin GPIO_PIN_9
#define Left_Key_GPIO_Port GPIOA
#define Right_Key_Pin GPIO_PIN_10
#define Right_Key_GPIO_Port GPIOA
#define Beep_Pin GPIO_PIN_15
#define Beep_GPIO_Port GPIOA
#define Right_Fine_Tune_Key_Pin GPIO_PIN_6
#define Right_Fine_Tune_Key_GPIO_Port GPIOB
#define Left_Fine_Tune_Key_Pin GPIO_PIN_7
#define Left_Fine_Tune_Key_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
