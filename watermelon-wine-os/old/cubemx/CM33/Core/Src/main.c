/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "copro_sync.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
DMA_HandleTypeDef handle_HPDMA1_Channel15;
DMA_HandleTypeDef handle_HPDMA1_Channel14;
DMA_HandleTypeDef handle_HPDMA1_Channel13;
DMA_HandleTypeDef handle_HPDMA1_Channel12;
DMA_HandleTypeDef handle_HPDMA1_Channel11;
DMA_HandleTypeDef handle_HPDMA1_Channel10;
DMA_HandleTypeDef handle_HPDMA1_Channel9;
DMA_HandleTypeDef handle_HPDMA1_Channel8;
DMA_HandleTypeDef handle_HPDMA1_Channel7;
DMA_HandleTypeDef handle_HPDMA1_Channel6;
DMA_HandleTypeDef handle_HPDMA1_Channel5;
DMA_HandleTypeDef handle_HPDMA1_Channel4;
DMA_HandleTypeDef handle_HPDMA1_Channel3;
DMA_HandleTypeDef handle_HPDMA1_Channel2;
DMA_HandleTypeDef handle_HPDMA1_Channel1;
DMA_HandleTypeDef handle_HPDMA1_Channel0;
DMA_HandleTypeDef handle_HPDMA2_Channel15;
DMA_HandleTypeDef handle_HPDMA2_Channel14;
DMA_HandleTypeDef handle_HPDMA2_Channel13;
DMA_HandleTypeDef handle_HPDMA2_Channel12;
DMA_HandleTypeDef handle_HPDMA2_Channel11;
DMA_HandleTypeDef handle_HPDMA2_Channel10;
DMA_HandleTypeDef handle_HPDMA2_Channel9;
DMA_HandleTypeDef handle_HPDMA2_Channel8;
DMA_HandleTypeDef handle_HPDMA2_Channel7;
DMA_HandleTypeDef handle_HPDMA2_Channel6;
DMA_HandleTypeDef handle_HPDMA2_Channel5;
DMA_HandleTypeDef handle_HPDMA2_Channel4;
DMA_HandleTypeDef handle_HPDMA2_Channel3;
DMA_HandleTypeDef handle_HPDMA2_Channel2;
DMA_HandleTypeDef handle_HPDMA2_Channel1;
DMA_HandleTypeDef handle_HPDMA2_Channel0;
DMA_HandleTypeDef handle_HPDMA3_Channel15;
DMA_HandleTypeDef handle_HPDMA3_Channel14;
DMA_HandleTypeDef handle_HPDMA3_Channel13;
DMA_HandleTypeDef handle_HPDMA3_Channel12;
DMA_HandleTypeDef handle_HPDMA3_Channel11;
DMA_HandleTypeDef handle_HPDMA3_Channel10;
DMA_HandleTypeDef handle_HPDMA3_Channel9;
DMA_HandleTypeDef handle_HPDMA3_Channel8;
DMA_HandleTypeDef handle_HPDMA3_Channel7;
DMA_HandleTypeDef handle_HPDMA3_Channel6;
DMA_HandleTypeDef handle_HPDMA3_Channel5;
DMA_HandleTypeDef handle_HPDMA3_Channel4;
DMA_HandleTypeDef handle_HPDMA3_Channel3;
DMA_HandleTypeDef handle_HPDMA3_Channel2;
DMA_HandleTypeDef handle_HPDMA3_Channel1;
DMA_HandleTypeDef handle_HPDMA3_Channel0;

IPCC_HandleTypeDef hipcc1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_HPDMA1_Init(void);
static void MX_HPDMA2_Init(void);
static void MX_HPDMA3_Init(void);
static void MX_IPCC1_Init(void);
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
  #if defined(DEBUG)
    volatile uint32_t debug = 1;
    while(debug);   // waiting for ST-LINK attachment. User can change "debug" to 0 to continue the execution.
  #endif

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

    /* Configure the system clock */
  if(IS_DEVELOPER_BOOT_MODE())
  {
    SystemClock_Config();
  }
  else
  {
   SystemCoreClockUpdate();
  }

  if(!IS_DEVELOPER_BOOT_MODE())
  {
    /* IPCC initialisation */
    MX_IPCC1_Init();
    /*Corpo Sync Initialization*/
    CoproSync_Init();
  }

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_HPDMA1_Init();
  MX_HPDMA2_Init();
  MX_HPDMA3_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
}

/**
  * @brief HPDMA1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_HPDMA1_Init(void)
{

  /* USER CODE BEGIN HPDMA1_Init 0 */

  /* USER CODE END HPDMA1_Init 0 */

  /* Peripheral clock enable */
  __HAL_RCC_HPDMA1_CLK_ENABLE();

  /* USER CODE BEGIN HPDMA1_Init 1 */

  /* USER CODE END HPDMA1_Init 1 */
  handle_HPDMA1_Channel15.Instance = HPDMA1_Channel15;
  handle_HPDMA1_Channel15.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel15.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel15.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel15.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel15.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel15.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel15.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel15.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel15.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel15.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel15.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel15.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel15.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel15) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel14.Instance = HPDMA1_Channel14;
  handle_HPDMA1_Channel14.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel14.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel14.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel14.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel14.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel14.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel14.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel14.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel14.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel14.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel14.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel14.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel14.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel14) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel13.Instance = HPDMA1_Channel13;
  handle_HPDMA1_Channel13.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel13.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel13.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel13.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel13.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel13.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel13.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel13.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel13.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel13.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel13.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel13.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel13.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel13) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel12.Instance = HPDMA1_Channel12;
  handle_HPDMA1_Channel12.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel12.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel12.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel12.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel12.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel12.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel12.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel12.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel12.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel12.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel12.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel12.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel12.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel12) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel11.Instance = HPDMA1_Channel11;
  handle_HPDMA1_Channel11.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel11.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel11.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel11.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel11.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel11.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel11.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel11.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel11.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel11.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel11.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel11.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel11.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel11) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel10.Instance = HPDMA1_Channel10;
  handle_HPDMA1_Channel10.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel10.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel10.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel10.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel10.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel10.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel10.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel10.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel10.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel10.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel10.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel10.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel10.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel10) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel9.Instance = HPDMA1_Channel9;
  handle_HPDMA1_Channel9.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel9.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel9.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel9.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel9.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel9.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel9.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel9.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel9.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel9.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel9.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel9.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel9.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel9) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel8.Instance = HPDMA1_Channel8;
  handle_HPDMA1_Channel8.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel8.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel8.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel8.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel8.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel8.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel8.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel8.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel8.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel8.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel8.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel8.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel8.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel8) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel7.Instance = HPDMA1_Channel7;
  handle_HPDMA1_Channel7.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel7.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel7.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel7.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel7.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel7.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel7.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel7.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel7.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel7.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel7.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel7.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel7.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel7) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel6.Instance = HPDMA1_Channel6;
  handle_HPDMA1_Channel6.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel6.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel6.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel6.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel6.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel6.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel6.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel6.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel6.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel6.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel6.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel6.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel6.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel6) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel5.Instance = HPDMA1_Channel5;
  handle_HPDMA1_Channel5.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel5.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel5.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel5.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel5.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel5.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel5.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel5.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel5.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel5.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel5.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel5.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel5.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel5) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel4.Instance = HPDMA1_Channel4;
  handle_HPDMA1_Channel4.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel4.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel4.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel4.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel4.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel4.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel4.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel4.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel4.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel4.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel4.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel4.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel4.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel4) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel3.Instance = HPDMA1_Channel3;
  handle_HPDMA1_Channel3.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel3.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel3.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel3.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel3.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel3.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel3.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel3.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel3.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel3.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel3.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel3.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel3.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel3) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel2.Instance = HPDMA1_Channel2;
  handle_HPDMA1_Channel2.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel2.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel2.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel2.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel2.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel2.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel2.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel2.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel2.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel2.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel2.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel2.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel2.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel2) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel1.Instance = HPDMA1_Channel1;
  handle_HPDMA1_Channel1.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel1.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel1.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel1.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel1.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel1.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel1.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel1.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel1.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel1.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel1.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel1.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel1.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel1) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA1_Channel0.Instance = HPDMA1_Channel0;
  handle_HPDMA1_Channel0.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA1_Channel0.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA1_Channel0.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA1_Channel0.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA1_Channel0.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA1_Channel0.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel0.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA1_Channel0.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA1_Channel0.Init.SrcBurstLength = 1;
  handle_HPDMA1_Channel0.Init.DestBurstLength = 1;
  handle_HPDMA1_Channel0.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA1_Channel0.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA1_Channel0.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA1_Channel0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HPDMA1_Init 2 */

  /* USER CODE END HPDMA1_Init 2 */

}

/**
  * @brief HPDMA2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_HPDMA2_Init(void)
{

  /* USER CODE BEGIN HPDMA2_Init 0 */

  /* USER CODE END HPDMA2_Init 0 */

  /* Peripheral clock enable */
  __HAL_RCC_HPDMA2_CLK_ENABLE();

  /* USER CODE BEGIN HPDMA2_Init 1 */

  /* USER CODE END HPDMA2_Init 1 */
  handle_HPDMA2_Channel15.Instance = HPDMA2_Channel15;
  handle_HPDMA2_Channel15.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel15.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel15.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel15.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel15.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel15.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel15.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel15.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel15.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel15.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel15.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel15.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel15.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel15) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel14.Instance = HPDMA2_Channel14;
  handle_HPDMA2_Channel14.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel14.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel14.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel14.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel14.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel14.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel14.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel14.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel14.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel14.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel14.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel14.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel14.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel14) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel13.Instance = HPDMA2_Channel13;
  handle_HPDMA2_Channel13.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel13.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel13.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel13.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel13.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel13.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel13.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel13.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel13.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel13.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel13.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel13.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel13.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel13) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel12.Instance = HPDMA2_Channel12;
  handle_HPDMA2_Channel12.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel12.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel12.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel12.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel12.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel12.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel12.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel12.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel12.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel12.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel12.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel12.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel12.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel12) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel11.Instance = HPDMA2_Channel11;
  handle_HPDMA2_Channel11.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel11.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel11.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel11.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel11.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel11.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel11.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel11.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel11.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel11.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel11.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel11.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel11.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel11) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel10.Instance = HPDMA2_Channel10;
  handle_HPDMA2_Channel10.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel10.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel10.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel10.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel10.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel10.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel10.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel10.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel10.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel10.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel10.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel10.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel10.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel10) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel9.Instance = HPDMA2_Channel9;
  handle_HPDMA2_Channel9.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel9.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel9.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel9.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel9.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel9.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel9.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel9.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel9.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel9.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel9.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel9.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel9.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel9) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel8.Instance = HPDMA2_Channel8;
  handle_HPDMA2_Channel8.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel8.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel8.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel8.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel8.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel8.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel8.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel8.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel8.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel8.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel8.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel8.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel8.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel8) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel7.Instance = HPDMA2_Channel7;
  handle_HPDMA2_Channel7.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel7.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel7.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel7.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel7.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel7.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel7.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel7.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel7.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel7.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel7.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel7.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel7.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel7) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel6.Instance = HPDMA2_Channel6;
  handle_HPDMA2_Channel6.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel6.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel6.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel6.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel6.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel6.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel6.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel6.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel6.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel6.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel6.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel6.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel6.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel6) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel5.Instance = HPDMA2_Channel5;
  handle_HPDMA2_Channel5.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel5.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel5.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel5.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel5.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel5.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel5.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel5.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel5.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel5.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel5.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel5.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel5.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel5) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel4.Instance = HPDMA2_Channel4;
  handle_HPDMA2_Channel4.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel4.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel4.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel4.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel4.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel4.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel4.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel4.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel4.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel4.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel4.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel4.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel4.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel4) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel3.Instance = HPDMA2_Channel3;
  handle_HPDMA2_Channel3.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel3.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel3.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel3.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel3.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel3.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel3.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel3.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel3.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel3.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel3.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel3.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel3.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel3) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel2.Instance = HPDMA2_Channel2;
  handle_HPDMA2_Channel2.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel2.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel2.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel2.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel2.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel2.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel2.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel2.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel2.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel2.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel2.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel2.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel2.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel2) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel1.Instance = HPDMA2_Channel1;
  handle_HPDMA2_Channel1.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel1.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel1.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel1.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel1.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel1.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel1.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel1.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel1.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel1.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel1.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel1.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel1.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel1) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA2_Channel0.Instance = HPDMA2_Channel0;
  handle_HPDMA2_Channel0.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA2_Channel0.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA2_Channel0.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA2_Channel0.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA2_Channel0.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA2_Channel0.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel0.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA2_Channel0.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA2_Channel0.Init.SrcBurstLength = 1;
  handle_HPDMA2_Channel0.Init.DestBurstLength = 1;
  handle_HPDMA2_Channel0.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA2_Channel0.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA2_Channel0.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA2_Channel0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HPDMA2_Init 2 */

  /* USER CODE END HPDMA2_Init 2 */

}

/**
  * @brief HPDMA3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_HPDMA3_Init(void)
{

  /* USER CODE BEGIN HPDMA3_Init 0 */

  /* USER CODE END HPDMA3_Init 0 */

  /* Peripheral clock enable */
  __HAL_RCC_HPDMA3_CLK_ENABLE();

  /* USER CODE BEGIN HPDMA3_Init 1 */

  /* USER CODE END HPDMA3_Init 1 */
  handle_HPDMA3_Channel15.Instance = HPDMA3_Channel15;
  handle_HPDMA3_Channel15.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel15.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel15.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel15.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel15.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel15.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel15.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel15.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel15.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel15.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel15.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel15.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel15.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel15) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel14.Instance = HPDMA3_Channel14;
  handle_HPDMA3_Channel14.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel14.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel14.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel14.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel14.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel14.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel14.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel14.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel14.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel14.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel14.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel14.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel14.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel14) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel13.Instance = HPDMA3_Channel13;
  handle_HPDMA3_Channel13.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel13.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel13.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel13.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel13.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel13.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel13.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel13.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel13.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel13.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel13.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel13.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel13.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel13) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel12.Instance = HPDMA3_Channel12;
  handle_HPDMA3_Channel12.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel12.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel12.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel12.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel12.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel12.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel12.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel12.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel12.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel12.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel12.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel12.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel12.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel12) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel11.Instance = HPDMA3_Channel11;
  handle_HPDMA3_Channel11.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel11.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel11.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel11.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel11.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel11.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel11.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel11.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel11.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel11.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel11.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel11.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel11.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel11) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel10.Instance = HPDMA3_Channel10;
  handle_HPDMA3_Channel10.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel10.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel10.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel10.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel10.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel10.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel10.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel10.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel10.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel10.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel10.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel10.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel10.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel10) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel9.Instance = HPDMA3_Channel9;
  handle_HPDMA3_Channel9.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel9.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel9.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel9.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel9.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel9.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel9.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel9.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel9.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel9.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel9.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel9.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel9.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel9) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel8.Instance = HPDMA3_Channel8;
  handle_HPDMA3_Channel8.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel8.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel8.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel8.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel8.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel8.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel8.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel8.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel8.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel8.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel8.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel8.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel8.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel8) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel7.Instance = HPDMA3_Channel7;
  handle_HPDMA3_Channel7.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel7.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel7.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel7.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel7.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel7.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel7.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel7.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel7.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel7.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel7.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel7.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel7.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel7) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel6.Instance = HPDMA3_Channel6;
  handle_HPDMA3_Channel6.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel6.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel6.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel6.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel6.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel6.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel6.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel6.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel6.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel6.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel6.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel6.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel6.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel6) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel5.Instance = HPDMA3_Channel5;
  handle_HPDMA3_Channel5.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel5.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel5.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel5.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel5.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel5.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel5.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel5.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel5.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel5.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel5.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel5.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel5.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel5) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel4.Instance = HPDMA3_Channel4;
  handle_HPDMA3_Channel4.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel4.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel4.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel4.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel4.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel4.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel4.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel4.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel4.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel4.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel4.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel4.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel4.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel4) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel3.Instance = HPDMA3_Channel3;
  handle_HPDMA3_Channel3.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel3.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel3.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel3.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel3.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel3.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel3.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel3.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel3.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel3.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel3.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel3.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel3.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel3) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel2.Instance = HPDMA3_Channel2;
  handle_HPDMA3_Channel2.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel2.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel2.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel2.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel2.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel2.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel2.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel2.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel2.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel2.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel2.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel2.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel2.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel2) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel1.Instance = HPDMA3_Channel1;
  handle_HPDMA3_Channel1.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel1.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel1.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel1.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel1.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel1.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel1.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel1.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel1.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel1.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel1.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel1.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel1.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel1) != HAL_OK)
  {
    Error_Handler();
  }
  handle_HPDMA3_Channel0.Instance = HPDMA3_Channel0;
  handle_HPDMA3_Channel0.Init.Request = DMA_REQUEST_SW;
  handle_HPDMA3_Channel0.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
  handle_HPDMA3_Channel0.Init.Direction = DMA_MEMORY_TO_MEMORY;
  handle_HPDMA3_Channel0.Init.SrcInc = DMA_SINC_FIXED;
  handle_HPDMA3_Channel0.Init.DestInc = DMA_DINC_FIXED;
  handle_HPDMA3_Channel0.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel0.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
  handle_HPDMA3_Channel0.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
  handle_HPDMA3_Channel0.Init.SrcBurstLength = 1;
  handle_HPDMA3_Channel0.Init.DestBurstLength = 1;
  handle_HPDMA3_Channel0.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT1|DMA_DEST_ALLOCATED_PORT1;
  handle_HPDMA3_Channel0.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
  handle_HPDMA3_Channel0.Init.Mode = DMA_NORMAL;
  if (HAL_DMA_Init(&handle_HPDMA3_Channel0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HPDMA3_Init 2 */

  /* USER CODE END HPDMA3_Init 2 */

}

/**
  * @brief IPCC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_IPCC1_Init(void)
{

  /* USER CODE BEGIN IPCC1_Init 0 */

  /* USER CODE END IPCC1_Init 0 */

  /* USER CODE BEGIN IPCC1_Init 1 */

  /* USER CODE END IPCC1_Init 1 */
  hipcc1.Instance = IPCC1;
  if (HAL_IPCC_Init(&hipcc1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IPCC1_Init 2 */

  /* USER CODE END IPCC1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
#ifdef USE_FULL_ASSERT
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
