# graduation_project_wheel_chair

Moving wheel chair code using AVR & Joystick module 
This project implements a motor control system using a microcontroller and a joystick interface.
The system reads analog values from two channels of an ADC (Analog-to-Digital Converter) representing the joystick's position along the X and Y axes. Based on these values, the system controls the direction and speed of two motors using PWM (Pulse Width Modulation) signals.

## Description

The code consists of several modules:

- **LIB**: Contains standard types and bit manipulation macros.
- **HAL/Motor_Driver**: Handles motor control functions.
- **MCAL/DIO_V1**: Provides digital I/O functions for interfacing with the motor driver.
- **MCAL/ADC_V1**: Initializes and reads analog values from the ADC.
- **MCAL/Timer_V2**: Configures and initializes timers for PWM generation.

### Features

- Control of two motors based on joystick input.
- Joystick input mapped to motor speed and direction.
- PWM-based speed control for smooth motor operation.

#### Prerequisites

Before running this code, ensure you have the following components:

- Microcontroller unit with ADC and PWM support
- Joystick interface for X and Y axes
- Motor driver circuitry to interface with the motors
- Standard C libraries
