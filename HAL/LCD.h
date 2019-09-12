/*
 * LCD.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Khaled
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

extern void LCD_vidInit(void);
extern void LCD_vidWriteChar(u8 ch);
extern void LCD_vidWriteString(u8* string);

extern void LCD_vidCrsrShiftLeft();
extern void LCD_vidCrsrShiftRight();
extern void LCD_vidDisplayShiftLeft();
extern void LCD_vidDisplayShiftRight();

extern void LCD_vidSetCGramAddress(u8 ins);
extern void LCD_vidSetCursor(u8 line, u8 position);
extern void LCD_vidClearDisplay();
extern void LCD_vidReturnHome();
#endif /* HAL_LCD_H_ */
