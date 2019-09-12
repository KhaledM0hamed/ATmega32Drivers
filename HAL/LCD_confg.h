/*
 * LCD_confg.h
 *
 *  Created on: Sep 10, 2019
 *      Author: khaled
 */

#ifndef HAL_LCD_CONFG_H_
#define HAL_LCD_CONFG_H_

#include "../MCAL/DIO.h"
// pins
#define data_port	PORTA
#define inst_port	PORTB
#define RSPin 		PIN0
#define RWPin 	 	PIN1
#define EPin  		PIN2

// Instructions
	// INIT
#define	FUNCTION_SET	0b00111000				// 0  0  1  1  N  F  X    X
#define DISPLAY_CONTROL 0b00001100				// 0  0  0  0  1  D  C    B
#define DISPLAY_CLEAR   0b00000001				// 0  0  0  0  0  0  0    1
#define ENTRY_MODE_SET  0b00000110				// 0  0  0  0  0  1  I/D  SH
	// INIT Ended
#define RETURN_HOME 	0b00000010				// 0  0  0  0  0  0  1    X
#define LEFT_CURSOR		0b00010000				// 0  0  0  0  0  0  X	  X
#define RIGHT_CURSOR	0b00010100				// 0  0  0  0  0  1  X	  X
#define LEFT_DISPLAY	0b00011000				// 0  0  0  0  1  0  X	  X
#define RIGHT_DISPLAY	0b00011100				// 0  0  0  0  1  1  X	  X
#endif /* HAL_LCD_CONFG_H_ */
