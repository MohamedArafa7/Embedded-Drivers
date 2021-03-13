/*
 * 8TH Project UART LCD GPIO.c
 *
 * Created: 1/29/2021 4:14:13 PM
 * Author : Arafa
 */ 

#include <avr/io.h>
#include "MyKit.h"
#include <util/delay.h>
#include "LCD4.h"
#include "GPIO.h"
#include "ExtInterrupt.h"
#include "UART.h"
#include <avr/interrupt.h>

ISR(USART_RXC_vect)
{
	char Rx = UDR;
	switch (Rx)
	{
		case 'A':
			Toggle_C(LEDC0);
			LCD4_Clear();
			LCD4_StrData("Sw 0 is pressed");
			break;
		case 'B':
			Toggle_C(LEDC1);
			LCD4_Clear();
			LCD4_StrData("Sw 1 is pressed");
			break;
		case 'C':
			Toggle_D(LEDD2);
			LCD4_Clear();
			LCD4_StrData("Sw 2 is pressed");
			break;
		default:
			break;
	}
	
}

int main(void)
{
    /* Replace with your application code */
	//Btn0_Init();
	//Dir_B(out_pin,0);
	Dir_B(in_pin,0); //Slave
	Btn1_Init();
	Btn2_Init();
	Dir_C(out_pin,LEDC0);
	Dir_C(out_pin,LEDC1);
	Dir_D(out_pin,LEDD2);
	LCD4_Init();
	UART_Init(9600);
	sei();
    while (1) 
    {
		if(IsPressed_Btn0())
		{
			UART_Data('A');
			_delay_ms(500);
		}
		else if(IsPressed_Btn1())
		{
			UART_Data('B');
			_delay_ms(500);
		}
		else if (IsPressed_Btn2())
		{
			UART_Data('C');
			_delay_ms(500);
		}
    }
}

