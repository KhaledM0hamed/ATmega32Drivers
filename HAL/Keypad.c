/*
 * Keypad.c
 *
 *  Created on: Sep 11, 2019
 *      Author: khaled
 */
#include "../STD_Types.h"
#include "../macros.h"
#include "Keypad.h"
#include "Keypad_confg.h"
#include "../MCAL/DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u8 keypad_columns[] = {C1, C2, C3, C4};
u8 keypad_rows[] = {R1, R2, R3, R4};

extern void Keypad_vidInit()
{
	u8 i;

	for (i = 0 ; i < ColmsNumber ; i++)
	{
		//set columns pins directions as output
		DIO_vidSetPinDir(KeypadPort, keypad_columns[i], OUTPUT);
		//set columns values as high
		DIO_vidSetPinValue(KeypadPort, keypad_columns[i], HIGH);
		//set rows pins directions as input
		DIO_vidSetPinDir(KeypadPort, keypad_rows[i], INPUT);
		//activate pull-up resistors
		DIO_vidSetPinValue(KeypadPort, keypad_rows[i],HIGH);
	}
}

extern u8 Keypad_u8GetPressedKey()
{
	u8 pressedKey = 0;
	u8 i, j;
	for (i = 0 ; i < ColmsNumber ; i++)
	{
		//activate columns
		DIO_vidSetPinValue(KeypadPort, keypad_columns[i], LOW);

		for (j = 0 ; j < RowsNumber ; j++)
		{
			if(DIO_u8GetPinaValue(KeypadPort, keypad_rows[j]) == LOW){
				pressedKey = ((j * ColmsNumber) + i + 1);
				//wait until the key being depressed
				while (DIO_u8GetPinaValue(KeypadPort,keypad_rows[j]));
			}
		}
		//deactivate the selected column
		DIO_vidSetPinValue(KeypadPort,keypad_columns[i],HIGH);
	}

	return pressedKey;
}





