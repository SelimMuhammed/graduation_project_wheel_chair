/*
 * ADC_reg.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */

#ifndef ADC_V1_ADC_REG_H_
#define ADC_V1_ADC_REG_H_
/*
 * ADC Multiplexer Selection Register
 */
#define ADMUX_REG      *((volatile u8*)0X27)
/*
 * ADC Control & Status Register A
 */
#define ADCS_REGA       *((volatile u8*)0X26)
/*
 * ADC Data Register
 */
#define ADC_REG       *((volatile u16*)0X24)
/*
 * Special Function IO Register
 */
#define SFIO_REG        *((volatile u8*)0X50)


#endif /* ADC_V1_ADC_REG_H_ */
