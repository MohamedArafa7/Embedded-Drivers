/*
 * 7th Project UART.c
 *
 * Created: 1/22/2021 7:13:52 PM
 * Author : Arafa
 */

#include "MyKit.h"
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include <avr/interrupt.h>
#include "GPIO.h"

ISR(USART_RXC_vect)
{
	char data = UDR;
	switch (data)
	{
		case 'A':
			//PORTA = 0xFF;
			_Led0(ON);
			break;
		case 'B':
			//PORTA = 0;
			_Led0(OFF);
			break;
		default:
			//PORTA = 0;
			break;
	}
}
int main(void)
{
    /* Replace with your application code */
	UART_Init(9600);
	//Config_A(out_Port);
	LEDInit();
	_Led0(OFF);
	
	//int x = 0;
	sei();
    while (1) 
    {
		UART_Data('A');
		_delay_ms(2000);
		UART_Data('B');
		_delay_ms(2000);
		/*UART_Str("X = ");
		UART_num(x++);
		UART_NL();
		_delay_ms(1000);*/
    }
}

