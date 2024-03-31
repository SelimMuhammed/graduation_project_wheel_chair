/*
 * ADC_Prg.c
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */
#include"../../LIB/stdtypes.h"
#include"../../LIB/BIT_MATH.h"
#include"ADC_reg.h"
#include"ADC_int.h"
#include"../DIO_V1/DIO_int.h"
#define RT_OK    (u8)   0
#define RT_NOK   (u8)   1

void ADC_Init(void)
{
	/* Prescaler = 8 */
	SET_BIT(ADCS_REGA,0);
	SET_BIT(ADCS_REGA,1);
	CLR_BIT(ADCS_REGA,2);

	/* VREF = VCC */
	SET_BIT(ADMUX_REG,6);
	CLR_BIT(ADMUX_REG,7);

	/* RESOLUTION = 10bit */
	CLR_BIT(ADMUX_REG,5);

	/* ADC ENABLE */
	SET_BIT(ADCS_REGA,7);
}

u16 ADC_u16Channelread(u8 Copy_u8Channel)
{
  // select the corresponding channel 0~7
  // ANDing with 7 will always keep the value
  // of Copy_u8Channel between 0 and 7
	ADMUX_REG &= 0b11100000;  // AND operation with 7 with ADMUX REG
	ADMUX_REG = ADMUX_REG |( Copy_u8Channel ); // clears the bottom 3 bits before ORing

  // start single convertion
  // write 1 to ADSC
	SET_BIT(ADCS_REGA,6);

  // wait for conversion to complete
  // ADSC becomes 0 again
  // till then, run loop continuously
  while(GET_BIT(ADCS_REGA,4)==0);
	/* Clear the Flag*/
  SET_BIT(ADCS_REGA,4);
	/*return the value*/
  return ADC_REG;
}

