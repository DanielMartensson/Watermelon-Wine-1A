/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32mp2xx_hal.h"
#include "stm32mp2xx_ll_ucpd.h"
#include "stm32mp2xx_ll_bus.h"
#include "stm32mp2xx_ll_rcc.h"
#include "stm32mp2xx_ll_system.h"
#include "stm32mp2xx_ll_pwr.h"
#include "stm32mp2xx_ll_gpio.h"
#include "stm32mp2xx_ll_dma.h"

#include "stm32mp2xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define VCONN_CC2_EN_Pin GPIO_PIN_3
#define VCONN_CC2_EN_GPIO_Port GPIOC
#define VCONN_CC1_EN_Pin GPIO_PIN_5
#define VCONN_CC1_EN_GPIO_Port GPIOF
#define USB_SWOE_Pin GPIO_PIN_2
#define USB_SWOE_GPIO_Port GPIOH
#define TCPP_INT_Pin GPIO_PIN_1
#define TCPP_INT_GPIO_Port GPIOG
#define BUTTON_USER2_Pin GPIO_PIN_11
#define BUTTON_USER2_GPIO_Port GPIOC
#define TCCP_EN_Pin GPIO_PIN_3
#define TCCP_EN_GPIO_Port GPIOA
#define USB_SWS_Pin GPIO_PIN_3
#define USB_SWS_GPIO_Port GPIOH
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOH

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
