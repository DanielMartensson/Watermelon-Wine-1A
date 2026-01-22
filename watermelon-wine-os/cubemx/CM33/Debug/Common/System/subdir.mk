################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/danie/Documents/GitHub/Watermelon-Wine-Zero-1A/firmware/Common/System/system_stm32mp2xx_m33.c 

OBJS += \
./Common/System/system_stm32mp2xx_m33.o 

C_DEPS += \
./Common/System/system_stm32mp2xx_m33.d 


# Each subdirectory must supply rules for building sources it contributes
Common/System/system_stm32mp2xx_m33.o: C:/Users/danie/Documents/GitHub/Watermelon-Wine-Zero-1A/firmware/Common/System/system_stm32mp2xx_m33.c Common/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DCORE_CM33 -DUSE_HAL_DRIVER -DSTM32MP257Fxx -c -I../Core/Inc -I../../Drivers/STM32MP2xx_HAL_Driver/Inc -I../../Drivers/STM32MP2xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32MP2xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-System

clean-Common-2f-System:
	-$(RM) ./Common/System/system_stm32mp2xx_m33.cyclo ./Common/System/system_stm32mp2xx_m33.d ./Common/System/system_stm32mp2xx_m33.o ./Common/System/system_stm32mp2xx_m33.su

.PHONY: clean-Common-2f-System

