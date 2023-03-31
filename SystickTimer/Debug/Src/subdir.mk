################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/RCFilter.c \
../Src/TimeFunctions.c \
../Src/adc.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/RCFilter.o \
./Src/TimeFunctions.o \
./Src/adc.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/RCFilter.d \
./Src/TimeFunctions.d \
./Src/adc.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DSTM32F446xx -c -I../Inc -I"D:/Embedded_System/Microcontrolling_Unit/Bare-Metal_Programming_ARM_Cortex-M/Chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Embedded_System/Microcontrolling_Unit/Bare-Metal_Programming_ARM_Cortex-M/Chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/RCFilter.d ./Src/RCFilter.o ./Src/RCFilter.su ./Src/TimeFunctions.d ./Src/TimeFunctions.o ./Src/TimeFunctions.su ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

