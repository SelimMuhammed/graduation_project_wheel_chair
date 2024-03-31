################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer_V2/subdir.mk
-include MCAL/DIO_V1/subdir.mk
-include MCAL/ADC_V1/subdir.mk
-include HAL/Motor_Driver/subdir.mk
-include HAL/LCD_Handler/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Wheel_Chair.lss \

FLASH_IMAGE += \
Wheel_Chair.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Wheel_Chair.elf secondary-outputs

# Tool invocations
Wheel_Chair.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Wheel_Chair.map -mmcu=atmega32 -o "Wheel_Chair.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Wheel_Chair.lss: Wheel_Chair.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Wheel_Chair.elf  >"Wheel_Chair.lss"
	@echo 'Finished building: $@'
	@echo ' '

Wheel_Chair.hex: Wheel_Chair.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Wheel_Chair.elf  "Wheel_Chair.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Wheel_Chair.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Wheel_Chair.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Wheel_Chair.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
