/*
 * Motor_int.h
 *
 *  Created on: Mar 9, 2023
 *      Author: selim
 */

#ifndef HAL_MOTOR_DRIVER_MOTOR_INT_H_
#define HAL_MOTOR_DRIVER_MOTOR_INT_H_

#define MOTOR_PORT      PORT_C
#define MOTOR_1_PIN_1   PIN_1
#define MOTOR_2_PIN_1   PIN_2

void Motor_voidInit(void);
void Motor_voidFoward(void);
void Motor_voidBackward(void);
void Motor_voidLeftDir(void);
void Motor_voidRigthDir(void);
void Motor_voidStop(void);

#endif /* HAL_MOTOR_DRIVER_MOTOR_INT_H_ */
