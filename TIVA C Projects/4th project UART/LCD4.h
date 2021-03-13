
#include"tm4c123gh6pm.h"

#define RsLCD4 1
#define EnLCD4  3
#define RWLCD4F 2

#define LCD_Data4 GPIO_PORTD_DATA_R


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

void LCD4_Init(void);
void LCD4_Command(char cmd);
void LCD4_Data(char data);
void LCD4_Clear(void);
void LCD4_Enable(void);
void LCD4_IntData(int data);
void LCD4_StrData(char* s);
