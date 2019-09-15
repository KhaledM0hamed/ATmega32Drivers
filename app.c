/*
 * app.c
 *
 *  Created on: Sep 10, 2019
 *      Author: khaled
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/DIO.h"
#include "MCAL/Interrupt.h"
#include "MCAL/Interrupt_confg.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void my_call_back(void){

DIO_vidSetPinValue(PORTA, PIN0,LOW);
_delay_ms(500);

}

int main()
{
	DIO_vidSetPinDir(PORTA, PIN0, OUTPUT);
	DIO_vidSetPinValue(PORTA, PIN0, HIGH);
	_delay_ms(3000);
	DIO_vidSetPinDir(PORTD, PIN2, INPUT);
	ExInterrupt_setCallBackFun(INT0, my_call_back);
	EXinterrupt_vidInit(INT0, falling_edge);

	DIO_vidSetPinDir(PORTB, PIN0, OUTPUT);
	DIO_vidSetPinValue(PORTB, PIN0, HIGH);
	DIO_vidSetPinValue(PORTB, PIN0, LOW);
	while(1)
		{

		}
	return 0 ;
}
/**/

