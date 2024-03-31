/*
 * ADC_int.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */
#include "../../LIB/stdtypes.h"
#ifndef ADC_V1_ADC_INT_H_
#define ADC_V1_ADC_INT_H_

#define ADSC                 (u8) 6
#define AREF_EN              (u8)0b00000000
#define AVCC_EN              (u8)0b01000000

#define ADC0_AREF            (u8)0b00000000
#define ADC1_AREF            (u8)0b00000001
#define ADC2_AREF            (u8)0b00000010
#define ADC3_AREF            (u8)0b00000011
#define ADC4_AREF            (u8)0b00000100
#define ADC5_AREF            (u8)0b00000101
#define ADC6_AREF            (u8)0b00000110
#define ADC7_AREF            (u8)0b00000111

#define ADC0_AVCC            (u8)0b01000000
#define ADC1_AVCC            (u8)0b01000001
#define ADC2_AVCC            (u8)0b01000010
#define ADC3_AVCC            (u8)0b01000011
#define ADC4_AVCC            (u8)0b01000100
#define ADC5_AVCC            (u8)0b01000101
#define ADC6_AVCC            (u8)0b01000110
#define ADC7_AVCC            (u8)0b01000111

#define ADC_EN_PS_2          (u8)0b10000000
#define ADC_EN_PS_4          (u8)0b10000010
#define ADC_EN_PS_8          (u8)0b10000011
#define ADC_EN_PS_16         (u8)0b10000100
#define ADC_EN_PS_32         (u8)0b10000101
#define ADC_EN_PS_64         (u8)0b10000110
#define ADC_EN_PS_128        (u8)0b10000111

typedef enum
{
	Channel_0,
	Channel_1,
	Channel_2,
	Channel_3,
	Channel_4,
	Channel_5,
	Channel_6,
	Channel_7
}ADC_Channels;

void ADC_Init(void);

u16 ADC_u16Channelread(u8 Copy_u8Channel);
#endif /* ADC_V1_ADC_INT_H_ */
