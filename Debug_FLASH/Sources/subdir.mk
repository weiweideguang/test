################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/delay.c \
../Sources/font.c \
../Sources/key.c \
../Sources/main.c \
../Sources/oled.c \
../Sources/uart.c 

OBJS += \
./Sources/delay.o \
./Sources/font.o \
./Sources/key.o \
./Sources/main.o \
./Sources/oled.o \
./Sources/uart.o 

C_DEPS += \
./Sources/delay.d \
./Sources/font.d \
./Sources/key.d \
./Sources/main.d \
./Sources/oled.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/delay.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


