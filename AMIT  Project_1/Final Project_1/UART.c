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
	
	//UCSRC = 0b11000110; //for synchronus*
	
		
	UART_BaudRate(BR);	// Call function to config baud rate
	UCSRB |= (1<<TXEN) | (1<<RXEN); // Enable Transmitter and receiver
	UCSRB |= 1<<RXCIE; /// Optional // Enable interrupt when receiving data
	
		
}
void UART_BaudRate(unsigned int rate)
{
	unsigned int BR = (F_CPU/(16.0 * rate))-1; // calculate  the value to config the baud rate 
	UBRRL = (char)BR;  // put the lower 8 bits for baud rate
	UBRRH &= ~(1 << URSEL); // Clear this bit to write the baud rate in this register
	UBRRH = (BR >> 8); // put the highest 4 bits for baud rate 
}
void UART_Data(char data)
{
	while (!(UCSRA & (1 << UDRE) ) ); // wait until Data register is Empty
	UDR = data; // put the data to send it
	
}
void UART_Str(char * data)
{
	for(int i = 0; data[i] != '\0';i++) // looping for all characters in the string until '\0' character
	{
		UART_Data(data[i]); // send char by char in the string
	}
	
}
void UART_num(int data)
{
	char str[11]; // array to save all possible integer digits
	itoa(data,str,10); // convert integer to string and put it in the array Str[]
	/*for(int i = 0;str[i] != '\0';i++)
	{
		UART_Data(str[i]);
	}*/
	UART_Str(str); // send array base address of the string number to be sent 
}
void UART_NL(void)
{
	UART_Data('\r'); // send new line char
}

char UART_RX(void)
{
	 while ( UCSRA & (1 << UDRE) ); // wail until data received ,, and data register contain data
	 return (char) UDR; //retern data;
}