/*
 * LCD8.c
 *
 * Created: 1/9/2021 9:10:42 PM
 *  Author: Arafa
 */ 
#include <stdlib.h>
#include "LDC8.h"
#include "GPIO.h"
#include <util/delay.h>
void LCD_Init(void)
{
	DataDir = 0xFF;
	CmdDir |= (1<<RsLCD) | (1 << EnLCD);
	LCD_Clear();
	LCD_Command(0x38);
	LCD_Command(0x0c);
	_delay_ms(10); 
	
}
void LCD_Command(char cmd)
{
	Data = cmd;
	ReSetPin_D(RsLCD);
	LCD_Enable();
}
void LCD_Data(char data)
{
	Data = data;
	SetPin_D(RsLCD);
	LCD_Enable();
	
}
void LCD_Clear(void)
{
	LCD_Command(LCDclear);
	//_delay_ms(1);
	LCD_Command(LCDhome);
}
void LCD_Enable(void)
{
	SetPin_D(EnLCD);
	_delay_ms(10);
	ReSetPin_D(EnLCD);
	_delay_ms(5);
}

void LCD_IntData(int data,int radix)
{
	char str[20];
	itoa(data,str,radix);
	for (int i = 0; str[i] !='\0';i++)
	{
		LCD_Data(str[i]);
	}
}
void LCD_StrData(char* s)
{
	for (int i = 0; s[i] !='\0';i++)
	{
		LCD_Data(s[i]);
	}
}