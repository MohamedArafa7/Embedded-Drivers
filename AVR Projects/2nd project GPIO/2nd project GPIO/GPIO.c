/*
 * GPIO.c
 *
 * Created: 1/8/2021 7:03:20 PM
 *  Author: Arafa
 */ 
#include <avr/io.h>
#include "MyKit.h"


char IsPressed_C(int PinNum)
{
	if(PINC & (1<<PinNum))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


char IsPressed_A(int PinNum)
{
	if(PINA & (1<<PinNum))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char IsPressed_B(int PinNum)
{
	if(PINB & (1<<PinNum))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char IsPressed_D(int PinNum)
{
	if(PIND & (1<<PinNum))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void SetPin_A(int PinNUM)
{
	PORTA |= 1<<PinNUM;
}
void SetPin_B(int PinNUM)
{
	PORTB |= 1<<PinNUM;
}
void SetPin_C(int PinNUM)
{
	PORTC |= 1<<PinNUM;
}
void SetPin_D(int PinNUM)
{
	PORTD |= 1<<PinNUM;
}


void ReSetPin_A(int PinNUM)
{
	PORTA &= ~(1<<PinNUM);
}
void ReSetPin_B(int PinNUM)
{
	PORTB &= ~(1<<PinNUM);
}
void ReSetPin_C(int PinNUM)
{
	PORTC &= ~(1<<PinNUM);
}
void ReSetPin_D(int PinNUM)
{
	PORTD &= ~(1<<PinNUM);
}
void Toggle_A(int PinNUM)
{
	PORTA ^= 1<<PinNUM;
}
void Toggle_B(int PinNUM)
{
	PORTB ^= 1<<PinNUM;
}
void Toggle_C(int PinNUM)
{
	PORTC ^= 1<<PinNUM;
}
void Toggle_D(int PinNUM)
{
	PORTD ^= 1<<PinNUM;
}


void Dir_A(char state,int PinNum)
{
	switch(state)
	{
		case in_pin:
			DDRA &= ~(1<<PinNum);
			break;
		case out_pin:
			DDRA |= 1<<PinNum;
			break;
		default:
			ReSetPin_A(PinNum);
	}
}

void Dir_B(char state,int PinNum)
{
	switch(state)
	{
		case in_pin:
		DDRB &= ~(1<<PinNum);
		break;
		case out_pin:
		DDRB |= 1<<PinNum;
		break;
		default:
		DDRB &= ~(1<<PinNum);
	}
}

void Dir_C(char state,int PinNum)
{
	switch(state)
	{
		case in_pin:
		DDRC &= ~(1<<PinNum);
		break;
		case out_pin:
		DDRC |= 1<<PinNum;
		break;
		default:
		DDRC &= ~(1<<PinNum);
	}
}

void Dir_D(char state,int PinNum)
{
	switch(state)
	{
		case in_pin:
		DDRD &= ~(1<<PinNum);
		break;
		case out_pin:
		DDRD |= 1<<PinNum;
		break;
		default:
		DDRD &= ~(1<<PinNum);
	}
}