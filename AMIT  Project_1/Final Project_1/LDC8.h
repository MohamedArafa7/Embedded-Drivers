/*
 * LDC8.h
 *
 * Created: 1/9/2021 9:10:54 PM
 *  Author: Arafa
 */ 
#include <avr/io.h>

#ifndef LDC8_H_
#define LDC8_H_


#define RsLCD 0
#define EnLCD  1 

#define Data PORTC
#define DataDir DDRC
#define CmdDir DDRD


#define LCDclear 0x01
#define LCDhome 0x02
#define CursorLeft 0x04
#define CursorRight 0x06
#define DisplayRight 0x05
#define DisplayLeft 0x07
#define DisplayCursorOff 0x08
#define DisplayCursorOn 0x0A
#define DisplayOnCursorOff 0x0C
#define CursorBlink 0x0E
#define cursorFirsLine 0x80
#define cursorSecondLine 0xC0
//#define CursorBlink 0x0F
//#define CursorLeft 0x10
//#define CursorRight 0x14
//#define DisplayLeft 0x18
//#define DisplayRight 0x1C

void LCD_Init(void);
void LCD_Command(char cmd);
void LCD_Data(char data);
void LCD_Clear(void);
void LCD_Enable(void);
void LCD_IntData(int data,int radix);
void LCD_StrData(char* s);




#endif /* LDC8_H_ */