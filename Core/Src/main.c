/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>

#include "led_functions.h"
#include "key_functions.h"
#include "beep_functions.h"
#include "rocker_functions.h"
#include "log.h"
#include "NRF24L01.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint16_t adc_result[4];
uint8_t nrf24l01_tx_buff[33];
uint8_t unlock_flag = 0;
uint8_t nrf24l01_tx_flag = 0;

uint8_t task_counter = 0;
uint8_t task_25hz_flag = 0;
uint8_t task_100hz_flag = 0;
uint8_t task_500hz_flag = 0;

__Key_Data key_data;
__Rocker_Data rocker_data;
uint16_t Key_Pin[6] = {Front_Fine_Tune_Key_Pin,Back_Fine_Tune_Key_Pin,
                       Left_Fine_Tune_Key_Pin,Right_Fine_Tune_Key_Pin,
                       Left_Key_Pin,Right_Key_Pin};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  POWER_ON_BEEP;
  
  HAL_TIM_Base_Start_IT(&htim2);

  HAL_ADC_Start_DMA(&hadc1,(uint32_t*)adc_result,8);
  /*
  while(!unlock_flag)
  {
    printf("RC Lock!!!\r\n");
    unlock_flag = Unlock(adc_result);
    HAL_Delay(1000);
  }
  */
  
  while(NRF24L01_Check())
	{
    printf("Can not find nrf24l01!!!\r\n");
		HAL_Delay(1000);
	}
  printf("NRF24L01 enter TX mode.\r\n");
  NRF24L01_TX_Mode();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    Key_Data_Write(GPIOB,Key_Pin,&key_data);
    Rocker_Data_ADC2Voltage(&rocker_data,adc_result);

    nrf24l01_tx_buff[0] = key_data.key_0;
    nrf24l01_tx_buff[1] = key_data.key_1;
    nrf24l01_tx_buff[2] = key_data.key_2;
    nrf24l01_tx_buff[3] = key_data.key_3;
    nrf24l01_tx_buff[4] = key_data.key_4;
    nrf24l01_tx_buff[5] = key_data.key_5;
    /*
    nrf24l01_tx_buff[6] = rocker_data.ch1_x * 100;
    nrf24l01_tx_buff[7] = rocker_data.ch1_y * 100;
    nrf24l01_tx_buff[8] = rocker_data.ch2_x * 100;
    nrf24l01_tx_buff[9] = rocker_data.ch2_y * 100;
    */
    
    nrf24l01_tx_flag = 0;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    
    if(NRF24L01_TxPacket(nrf24l01_tx_buff)==TX_OK)
    {
      printf("Tx success.\r\n");
      nrf24l01_tx_flag = 1;
      LED_Green_ON;
    }
    else
    {
      printf("TX error!!!\r\n");
      nrf24l01_tx_flag = 0;
      LED_Green_OFF;
    } 

    HAL_Delay(1000);
    

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 144;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htm)
{
  task_counter++;
  if(task_counter%2 == 0) 
    task_500hz_flag = 1;
  else if(task_counter%10 == 0)
    task_100hz_flag = 1;
  else if(task_counter%40 == 0)
  {
    task_25hz_flag = 1;
    task_counter = 0;
  }
  else
  {
    task_500hz_flag = 0;
    task_100hz_flag = 0;
    task_25hz_flag = 0;
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
