/*
 * LCD.c
 *
 *  Created on: Sep 10, 2019
 *      Author: Khaled
 */

#include "../STD_Types.h"
#include "../macros.h"
#include "LCD.h"
#include "LCD_confg.h"

#define F_CPU	8000000UL
#include "util/delay.h"
#include "../MCAL/DIO.h"

static void LOC_vidSendInstruction(u8 Ins);


// 8-Bit Initialization.
extern void LCD_vidInit(void)
{
	DIO_vidSetPortDir(data_port,OUTPUT);				// set data port direction
	DIO_vidSetPinDir(inst_port,RSPin,OUTPUT);			// set RS pin direction
	DIO_vidSetPinDir(inst_port,RWPin,OUTPUT);			// set R/W pin direction
	DIO_vidSetPinDir(inst_port,EPin,OUTPUT);			// set E pin direction

	_delay_ms(30);										// wait until V rises to 4.5v
	LOC_vidSendInstruction(FUNCTION_SET);      		  	// N = 1, F = 0
	_delay_ms(2);
	LOC_vidSendInstruction(DISPLAY_CONTROL);			// D = 1, C = 0, B = 0
	_delay_ms(2);
	LOC_vidSendInstruction(DISPLAY_CLEAR);
	_delay_ms(2);
	LOC_vidSendInstruction(ENTRY_MODE_SET);				// I/D = 1, S = 0
	_delay_ms(2);
}

// locally sending instruction.
static void LOC_vidSendInstruction(u8 Ins)
{
	/*set RS=0*/
	DIO_vidSetPinValue(inst_port,RSPin,LOW);
	/*set RW=0*/
	DIO_vidSetPinValue(inst_port,RWPin,LOW);
	/*set D0~D7*/
	DIO_vidSetPortValue(data_port,Ins);
	/*Enable Falling edge*/
	DIO_vidSetPinValue(inst_port,EPin,HIGH);
	_delay_ms(1);
	DIO_vidSetPinValue(inst_port,EPin,LOW);
}

// Write Char
extern void LCD_vidWriteChar(u8 ch)
{
	/*set RS=1*/
	DIO_vidSetPinValue(inst_port,RSPin,HIGH);
	/*set RW=0*/
	DIO_vidSetPinValue(inst_port,RWPin,LOW);
	/*set D0~D7*/
	DIO_vidSetPortValue(data_port,ch);
	/*Enable Falling edge*/
	DIO_vidSetPinValue(inst_port,EPin,HIGH);
	_delay_ms(1);
	DIO_vidSetPinValue(inst_port,EPin,LOW);

}

// Write String
extern void LCD_vidWriteString(u8* string)
{
	while (*string){
		LCD_vidWriteChar(*string++);
	}
}

// Cursor or Display Shift
extern void LCD_vidCrsrShiftLeft()
{
	LOC_vidSendInstruction(LEFT_CURSOR);
}

extern void LCD_vidCrsrShiftRight()
{
	LOC_vidSendInstruction(RIGHT_CURSOR);
}

extern void LCD_vidDisplayShiftLeft()
{
	LOC_vidSendInstruction(LEFT_DISPLAY);
}

extern void LCD_vidDisplayShiftRight()
{
	LOC_vidSendInstruction(RIGHT_DISPLAY);
}

// Set CGRAM or DDRAM address

// CGRAM -> 0 1   AC5 AC4 AC3 AC2 AC1 AC0
// DDRAM -> 1 AC6 AC5 AC4 AC3 AC2 AC1 AC0
extern void LCD_vidSetCGDDAddress(u8 ins)
{
	LOC_vidSendInstruction(ins);
}


// Set Cursor
extern void LCD_vidSetCursor(u8 line, u8 position)
{
	switch (line)
	{
		case 1:
			LOC_vidSendInstruction(128+position);
			break;
		case 2:
			LOC_vidSendInstruction(192+position);
			break;
		default:
			break;
	}
}

// Clear Display
extern void LCD_vidClearDisplay()
{
	LOC_vidSendInstruction(DISPLAY_CLEAR);
}

// Return home
extern void LCD_vidReturnHome()
{
	LOC_vidSendInstruction(RETURN_HOME);
}
