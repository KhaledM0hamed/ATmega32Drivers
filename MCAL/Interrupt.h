/*
 * Interrupt.h
 *
 *  Created on: Sep 14, 2019
 *      Author: khale
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_
#include "../MCAL/DIO.h"
/*MCUSR
// SE	SM2		SM1		SM0		ISC11		ISC10		ISC01		ISC00
INT1 Sense Control
ISC11 	ISC10 	Description
0 		0 		The low level of INT1 generates an interrupt request.
0 		1 		Any logical change on INT1 generates an interrupt request.
1 		0 		The falling edge of INT1 generates an interrupt request.
1 		1 		The rising edge of INT1 generates an interrupt request.

INT0 Sense Control
ISC01 	ISC00 	Description
0 		0 		The low level of INT0 generates an interrupt request.
0 		1 		Any logical change on INT0 generates an interrupt request.
1 		0 		The falling edge of INT0 generates an interrupt request.
1 		1 		The rising edge of INT0 generates an interrupt request.*/
#define MCUCR	*((volatile u8*) 0x55)
#define ISC00	0
#define ISC01   1
#define ISC10   2
#define ISC11	3
#define SM0		4
#define SM1		5
#define SM2		6
#define SE      7
/*MCUCSR */
#define MCUCSR	*((volatile u8*) 0x54)
#define ISC2	6
/*GICR */
#define GICR	*((volatile u8*) 0x5B)
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/*GIFR */
#define GIFR 	*((volatile u8*) 0x5A)
#define INTF1	7
#define INTF0	6
#define INTF2	5


/*SREG */
#define SREG 	*((volatile u8*) 0x5F)
#define SREG_I	7
//--------------- Function ---------------//
#define vect_INT0	1
#define vect_INT1	2
#define vect_INT2	3
//ISR
#define vect(x) __vector_##x

#  define ISR(vector, ...)            \
    void vect(vector) (void) __attribute__ ((signal)); \
    void vect(vector) (void)


// External Interrupt initialization
extern void EXinterrupt_vidInit(u8 INTx, u8 mode);

extern void ExInterrupt_setCallBackFun(u8 INTx, void (*ptr)(void) );
#endif /* MCAL_INTERRUPT_H_ */
