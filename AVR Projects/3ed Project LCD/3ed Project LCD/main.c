/*
 * 3ed Project LCD.c
 *
 * Created: 1/9/2021 6:15:16 PM
 * Author : Arafa
 */ 
#include "MyKit.h"
#include <avr/io.h>
#include <util/delay.h>
#include "GPIO.h"
//#include "LDC8.h"
#include "LCD4.h"


#define hex 16
#define dis 10
#define bin 2

int main(void)
{
    /* Replace with your application code */
	//int x = 1000;
	LCD4_Init();
	LCD4_Data('A');
	_delay_ms(2000);
	LCD4_Clear();
	LCD4_IntData(-12345,dis);
	_delay_ms(2000);
	//LCD_Clear();
	//LCD_StrData("Arafa");
	
    while (1) 
    {
		
		
    }
}

