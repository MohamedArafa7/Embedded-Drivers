/*
 * LCD4.h
 *
 * Created: 1/15/2021 7:18:36 PM
 *  Author: Arafa
 */ 


#ifndef LCD4_H_
#define LCD4_H_

#define RsLCD4 1
#define EnLCD4  3
#define RWLCD4 2

#define Data4 PORTA
#define DataDir4 DDRA
#define CmdDir4 DDRB
#define RW PORTB


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

void LCD4_Init(void);
void LCD4_Command(char cmd);
void LCD4_Data(char data);
void LCD4_Clear(void);
void LCD4_Enable(void);
void LCD4_IntData(int data,int radix);
void LCD4_StrData(char* s);


#endif /* LDC4_H_ */
