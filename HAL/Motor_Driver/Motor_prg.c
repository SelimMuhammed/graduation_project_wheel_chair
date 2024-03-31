/*
 * Motor.c
 *
 *  Created on: Mar 9, 2023
 *      Author: selim
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stdtypes.h"
#include "../../MCAL/DIO_V1/DIO_int.h"
#include "Motor_int.h"


void Motor_voidInit(void)
{
  DIO_u8setPinDirection(MOTOR_PORT,MOTOR_1_PIN_1,OUTPUT);
  DIO_u8setPinDirection(MOTOR_PORT,MOTOR_2_PIN_1,OUTPUT);

}
void Motor_voidFoward(void)
{
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_1_PIN_1,HIGH);
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_2_PIN_1,HIGH);
}
void Motor_voidBackward(void)
{
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_1_PIN_1,LOW);
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_2_PIN_1,LOW);
}
void Motor_voidLeftDir(void)
{
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_1_PIN_1,HIGH);
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_2_PIN_1,LOW);
}
void Motor_voidRigthDir(void)
{
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_1_PIN_1,LOW);
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_2_PIN_1,HIGH);
}
void Motor_voidStop(void)
{
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_1_PIN_1,LOW);
 DIO_u8setPinValue(MOTOR_PORT,MOTOR_2_PIN_1,LOW);
}
