#include "MyKit.h"
#include <stdlib.h>
#include "GPIO.h"
#include <util/delay.h>
#include "LCD4.h"


void LCD4_Init(void)
{
	DataDir4 |= 0xF0;
	CmdDir4 |= (1<<RsLCD4) | (1 << EnLCD4)| (1<<RWLCD4);
	RW &= ~(1<<RWLCD4);
	
	LCD4_Command(0x02);  // 8_bit Mode
	LCD4_Command(0x0c); // Cursor off,display on
	_delay_ms(10);
	LCD4_Clear();
	
	
}
void LCD4_Command(char cmd)
{
		Data4 = (Data4 & 0x0F)|((cmd & 0xF0));
		ReSetPin_B(RsLCD4);
		LCD4_Enable();
		_delay_ms(1);
	Data4 = (Data4 & 0x0F)| ((cmd & 0x0F)<<4);
	ReSetPin_B(RsLCD4);
	LCD4_Enable();

	
}
void LCD4_Data(char data)
{
		Data4 = (Data4 & 0x0F)|((data & 0xF0));
		SetPin_B(RsLCD4);
		LCD4_Enable();
		_delay_ms(1);
	Data4 = (Data4 & 0x0F)|((data & 0x0F)<<4);
	SetPin_B(RsLCD4);
	LCD4_Enable();
	

	
}
void LCD4_Clear(void)
{
	LCD4_Command(LCDclear);
	_delay_ms(1);
	//LCD4_Command(LCD4home);
}
void LCD4_Enable(void)
{
	SetPin_B(EnLCD4);
	_delay_ms(10);
	ReSetPin_B(EnLCD4);
	_delay_ms(5);
}
void LCD4_StrData(char* s)
{
	for (int i = 0; s[i] !='\0';i++)
	{
		LCD4_Data(s[i]);
	}
}
void LCD4_IntData(int data,int radix)
{
	char str[20];
	itoa(data,str,radix);
	LCD4_StrData(str);
}
