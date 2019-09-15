/*
 * interrupt.c
 *
 *  Created on: Sep 14, 2019
 *      Author: khale
 */
#include "../STD_Types.h"
#include "../macros.h"
#include "../MCAL/DIO.h"
#include "../MCAL/Interrupt.h"
#include "../MCAL/Interrupt_confg.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void (*call_back_fun0)(void);
void (*call_back_fun1)(void);
void (*call_back_fun2)(void);


extern void EXinterrupt_vidInit(u8 INTx, u8 mode){
	switch (INTx)
	{
		case INT0:
			if (mode == low_level){
				//set INT0 as low level mode.
				//clear ISC01 & ISC00.
				clr_bit(MCUCR, ISC00);
				clr_bit(MCUCR, ISC01);
			}else if (mode == logical_change){
				//set INT0 as a logical change mode.
				//clear ISC01 & set ISC00.
				clr_bit(MCUCR, ISC00);
				set_bit(MCUCR, ISC01);
			}else if (mode == falling_edge){
				//set INT0 as a falling edge mode.
				//set ISC01 & clear ISC00.
				set_bit(MCUCR, ISC00);
				clr_bit(MCUCR, ISC01);
			}else if (mode == rising_edge){
				//set INT0 as a rising edge mode.
				//set ISC01 & ISC00.
				set_bit(MCUCR, ISC00);
				set_bit(MCUCR, ISC01);
			}else{
				break;
			}
			// Enable INT0
			set_bit(GICR,INT0);
			// Enable Global INT
			set_bit(SREG, SREG_I);
			break;
		case INT1:
			if (mode == low_level){
				//set INT1 as low level mode.
				//clear ISC11 & ISC10.
				clr_bit(MCUCR, ISC10);
				clr_bit(MCUCR, ISC11);
			}else if (mode == logical_change){
				//set INT1 as a logical change mode.
				//clear ISC11 & set ISC10.
				clr_bit(MCUCR, ISC10);
				set_bit(MCUCR, ISC11);
			}else if (mode == falling_edge){
				//set INT1 as a falling edge mode.
				//set ISC11 & clear ISC10.
				set_bit(MCUCR, ISC10);
				clr_bit(MCUCR, ISC11);
			}else if (mode == rising_edge){
				//set INT1 as a rising edge mode.
				//set ISC11 & ISC10.
				set_bit(MCUCR, ISC10);
				set_bit(MCUCR, ISC11);
			}else{
				break;
			}
			// Enable INT1
			set_bit(GICR,INT1);
			// Enable Global INT
			set_bit(SREG, SREG_I);
			break;

		case INT2:
			if (mode == falling_edge){
				clr_bit(MCUCSR, ISC2);
			}else if (mode == rising_edge){
				set_bit(MCUCSR, ISC2);
			}else{
				break;
			}
			// Enable INT2
			set_bit(GICR,INT2);
			// Enable Global INT
			set_bit(SREG, SREG_I);
			break;
	}



}

extern void ExInterrupt_setCallBackFun(u8 INTx, void (*ptr)(void) ){
	switch (INTx){
		case INT0:
			call_back_fun0 = ptr;
			break;
		case INT1:
			call_back_fun1 = ptr;
			break;
		case INT2:
			call_back_fun2 = ptr;
			break;
	}
}

ISR(vect_INT0){
	call_back_fun0();
}

ISR(vect_INT1){
	call_back_fun1();
}

ISR(vect_INT2){
	call_back_fun2();
}
