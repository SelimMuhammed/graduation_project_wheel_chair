/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: hp
 */
#include "../LIB/stdtypes.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/Motor_Driver/Motor_int.h"
#include "../MCAL/DIO_V1/DIO_int.h"
#include "../MCAL/ADC_V1/ADC_int.h"
#include "../MCAL/Timer_V2/Timer_int.h"
#include "../MCAL/Timer_V2/Timer_reg.h"



// The Mapping Function
u32 map(u32 Value, u32 in_min, u32 in_max, u32 out_min, u32 out_max)
{
	return (Value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void main(void)
{
	s16 Digital_Val_X, Digital_Val_Y;
	PWM_timers_config MOTOR1_PWM;
	PWM_timers_config MOTOR2_PWM;
	// Set TIMER 0 in Fast PWM Mode
	MOTOR1_PWM.timer = TIMER_0;
	MOTOR1_PWM.PWM_Mode = FAST_PWM;

	// Starting TIMER 0 with prescaler 8
	MOTOR1_PWM.T0_T1_used_freq = TIMER_0_1_PRE_SCALER_e_8;
	MOTOR1_PWM.set_duty_cycle = 0;

	// Set TIMER 2 in Fast PWM Mode
	MOTOR2_PWM.timer = TIMER_2;
	MOTOR2_PWM.PWM_Mode = FAST_PWM;

	// Starting TIMER 2 with prescaler 8
	MOTOR2_PWM.T2_used_freq = TIMER_2_PRE_SCALER_e_8;
	MOTOR2_PWM.set_duty_cycle = 0;


	// Initilizing PWM Function
	PWM_timers_init(&MOTOR1_PWM);
	PWM_timers_init(&MOTOR2_PWM);

	// Initializing ADC with VREF = VCC and a division factor 8
	ADC_Init();
	Motor_voidInit();

	while(1)
	{
		Digital_Val_X = ADC_u16Channelread(Channel_0);
		Digital_Val_Y = ADC_u16Channelread(Channel_1);

		if((Digital_Val_X>=-60 && Digital_Val_X<490) && (Digital_Val_Y>491 && Digital_Val_Y<529))
		{
			Digital_Val_X = map(Digital_Val_X,-60,490,180,0);
			OCR0_REG = Digital_Val_X;
			OCR2_REG = Digital_Val_X;
			Motor_voidBackward();
		}
		else if((Digital_Val_X>530 && Digital_Val_X<1023) && (Digital_Val_Y>491 && Digital_Val_Y<529))
		{
			Digital_Val_X = map(Digital_Val_X,530,1023,0,180);
			OCR0_REG = Digital_Val_X;
			OCR2_REG = Digital_Val_X;
			Motor_voidFoward();
		}
		else if((Digital_Val_X>491 && Digital_Val_X<529) && (Digital_Val_Y>491 && Digital_Val_Y<529))
		{
			Digital_Val_X= map(Digital_Val_X,491,529,0,0);
			OCR0_REG = Digital_Val_X;
			OCR2_REG = Digital_Val_X;
			Motor_voidStop();
		}


		else if((Digital_Val_Y>=0 && Digital_Val_Y<490) && (Digital_Val_X>491 && Digital_Val_X<529))
		{
			Digital_Val_Y = map(Digital_Val_Y,-60,490,180,0);
			OCR0_REG = Digital_Val_Y;
			OCR2_REG = Digital_Val_Y;
			Motor_voidRigthDir();
		}
		else if((Digital_Val_Y>530 && Digital_Val_Y<1023) && (Digital_Val_X>491 && Digital_Val_X<529))
		{
			Digital_Val_Y = map(Digital_Val_Y,530,1023,0,180);
			OCR0_REG = Digital_Val_Y;
			OCR2_REG = Digital_Val_Y;
			Motor_voidLeftDir();
		}

	}

}


