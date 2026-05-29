#-------------------------------------------------------------------------------
# Copyright (c) 2026, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# set board specific config
########################## STM32 #######################################
#Before Soc config

# set common soc config

#   /* USER CODE BEGIN addons-0 */
if (EXISTS ${STM_SOC_DIR}/config.cmake)
    include(${STM_SOC_DIR}/config.cmake)
endif()

#After soc config
set(STM32_BOARD_MODEL           "stm32mp257f-mx"	               	CACHE STRING	"Define board model name" FORCE)
#   /* USER CODE END addons-0 */

set(STM32_DDR_PHY_FILE          "ddr4_pmu_train.bin"	CACHE STRING    "Set ddr phy binary name need for your board" FORCE)
set(STM32_DDR_TYPE STM32MP_DDR4_TYPE CACHE STRING  "Set ddr type flag" FORCE)
set(STM32_DDR_SIZE 0x100000000 CACHE STRING "Set ddr size in Bytes" FORCE)
set(STM32_DDR_FREQ 1200000 CACHE STRING "Set ddr frequency in KHz" FORCE)

#    /* USER CODE BEGIN ospi_nor */
set(TFM_PARTITION_PROTECTED_STORAGE OFF CACHE BOOL "Enable Protected Storage partition" FORCE)
#    /* USER CODE BEGIN ospi_nor */

