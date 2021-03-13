/*
 * UARTc.c
 *
 * Created: 1/23/2021 6:11:25 PM
 *  Author: Arafa
 */ 

#include "MyKit.h"
#include <avr/io.h>
#include "UART.h"
#include <stdlib.h>
#include "GPIO.h"
void UART_Init(unsigned int BR)
{
	
	/*UART_BaudRate(BR);
	Dir_B(out_pin,0); //Master
	UCSRC = 0b11000111; //for synchronus
	*/
	
	UCSRC = 0b11000110; //for synchronus*
	
		
	//UART_BaudRate(BR);	
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UCSRB |= 1<<RXCIE; /// Optional
	
		
}
void UART_BaudRate(unsigned int rate)
{
	unsigned int BR = (F_CPU/(16.0 * rate))-1;
	UBRRL = (char)BR;
	UBRRH = (BR >> 8);
}
void UART_Data(char data)
{
	while (!(UCSRA & (1 << UDRE) ) );
	UDR = data;
	
}
void UART_Str(char * data)
{
	for(int i = 0; data[i] != '\0';i++)
	{
		UART_Data(data[i]);
	}
	
}
void UART_num(int data)
{
	char str[11];
	itoa(data,str,10);
	/*for(int i = 0;str[i] != '\0';i++)
	{
		UART_Data(str[i]);
	}*/
	UART_Str(str);
}
void UART_NL(void)
{
	UART_Data('\r');
}

char UART_RX(void);
