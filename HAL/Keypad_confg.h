/*
 * Keypad_confg.h
 *
 *  Created on: Sep 11, 2019
 *      Author: khale
 */

#ifndef HAL_KEYPAD_CONFG_H_
#define HAL_KEYPAD_CONFG_H_

#include "../STD_Types.h"
#include "../MCAL/DIO.h"

#define KeypadPort	PORTC
#define C1			PIN0
#define C2			PIN1
#define C3			PIN2
#define C4			PIN3
#define R1			PIN4
#define R2			PIN5
#define R3			PIN6
#define R4			PIN7

#define ColmsNumber		4
#define RowsNumber		4


typedef enum
{
	Key_No1 = 1 ,
	Key_No2 = 2 ,
	Key_No3 = 3 ,
	Key_No4 = 5,
	Key_No5 = 6,
	Key_No6 = 7,
	Key_No7 = 9,
	Key_No8 = 10,
	Key_No9 = 11,
	Key_No0 = 14,
	Key_A = 4,
	Key_B = 8,
	Key_C = 12,
	Key_D = 16,
	Key_STAR = 13,
	Key_HASH = 15,
	Key_NONE = 0
}KeyPadKey ;


#endif /* HAL_KEYPAD_CONFG_H_ */
