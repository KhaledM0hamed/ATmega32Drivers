/*
 * app.c
 *
 *  Created on: Sep 10, 2019
 *      Author: khaled
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "HAL/LCD_confg.h"
#include "HAL/Keypad.h"
#include "HAL/Keypad_confg.h"


int main()
{
	LCD_vidInit();
	Keypad_vidInit();

		u8 key = Key_NONE;
		while (key == Key_NONE){
			key = Keypad_u8GetPressedKey();
		}
		u8 string[] = "khaledeee";
		LCD_vidWriteString(string);
		switch (key){
					case Key_No1:  LCD_vidWriteChar('1'); break;
					case Key_No2:  LCD_vidWriteChar('2'); break;
					case Key_No3:  LCD_vidWriteChar('3'); break;
					case Key_No4:  LCD_vidWriteChar('4'); break;
					case Key_No5:  LCD_vidWriteChar('5'); break;
					case Key_No6:  LCD_vidWriteChar('6'); break;
					case Key_No7:  LCD_vidWriteChar('7'); break;
					case Key_No8:  LCD_vidWriteChar('8'); break;
					case Key_No9:  LCD_vidWriteChar('9'); break;
					case Key_No0:  LCD_vidWriteChar('0'); break;
					case Key_NONE:  break;
					case Key_HASH: LCD_vidWriteChar('#'); break;
					case Key_STAR: LCD_vidWriteChar('*'); break;
					case Key_A: LCD_vidWriteChar('+'); break;
					case Key_B: LCD_vidWriteChar('-'); break;
					case Key_C: LCD_vidWriteChar('*'); break;
					case Key_D: LCD_vidWriteChar('/'); break;
					}


		while(1)
			{

			}
	return 0 ;
}
