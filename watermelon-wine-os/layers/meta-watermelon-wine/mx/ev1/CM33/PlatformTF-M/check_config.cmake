#-------------------------------------------------------------------------------
# Copyright (c) 2026, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

  # /* USER CODE BEGIN addons */
if (EXISTS ${STM_SOC_DIR}/check_config.cmake)
    include(${STM_SOC_DIR}/check_config.cmake)
endif()
tfm_invalid_config(TFM_PARTITION_PROTECTED_STORAGE)
  # /* USER CODE END addons */

