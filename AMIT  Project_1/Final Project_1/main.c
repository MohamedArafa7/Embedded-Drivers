/*
 * Final Project_1.c
 *
 * Created: 3/5/2021 10:35:25 AM
 * Author : My Heart
 */ 
#include "MyKit.h"
#include <avr/io.h>
#include "GPIO.h"
#include "UART.h"
#include "SPI.h"
#include "LCD4.h"
#include "TIMER.h"
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(USART_RXC_vect)
{
	char RXData = (char)UDR; // Read received data
	SPI_ChangeMode(Master);
	_delay_ms(10);
	switch (RXData) // Cheek the data received
	{
		case 'A':
		case 'a':
			_Led2(ON);
			SPI_Data('A');		//Send data using SPI
			break;

		case 'B':
		case 'b':
			_Led2(OFF);
			SPI_Data('B');		//Send data using SPI
			break;

		case 'C':
		case 'c':
			_Led2(ON);
			SPI_Data('C'); //Send data using SPI
			break;

		case 'D':
		case 'd':
			_Led2(OFF);
			SPI_Data('D');//Send data using SPI
			break;

		default://Do nothing
			break;
	}
	SPI_ChangeMode(Slave);
}

ISR(SPI_STC_vect)
{
		char SPIData = SPDR; // Read received data
		switch (SPIData) // Cheek the data received
		{
			case 'A':
			case 'a':
				_Led0(ON);
				break;

			case 'B':
			case 'b':
				_Led0(OFF);
				break;
				
			case 'C':
			case 'c':
				_Led1(ON);
				break;

			case 'D':
			case 'd':
				_Led1(OFF);
				break;
				
			default://Do nothing
			break;
		}
}

int main(void)
{
    /* Replace with your application code */
			Dir_C(out_pin,LEDC0);  // Set PinC2 output for LED0 in Kit
			Dir_C(out_pin,LEDC1);  // Set PinC7 output for LED1 in Kit
			Dir_D(out_pin,LEDD2);
			
			UART_Init(9600); // initialize UART module with 9600 baud rate
			
			SPI_Init(Slave,SPI_CLK_Div128);
			SPI_Interrupt_Enable();
			SPI_Enable();
			
			sei();
			
    while (1) 
    {
		
    }
}

