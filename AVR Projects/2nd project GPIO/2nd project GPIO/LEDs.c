/*
 * LEDs.c
 *
 * Created: 1/9/2021 11:22:42 AM
 *  Author: Arafa
 */ 
#include "MyKit.h"
#include "GPIO.h"

void LEDInit(void)
{
	Dir_C(out_pin,LEDC0);
	Dir_C(out_pin,LEDC1);
	Dir_D(out_pin,LEDD2);
}

void _Led0(char state)
{
	switch(state)
	{
		case ON:
		SetPin_C(LEDC0);
		break;
		case OFF:
		ReSetPin_C(LEDC0);
		break;
		default:
		ReSetPin_C(LEDC0);
	}
}
void _Led1(char state)
{
	switch(state)
	{
		case ON:
		SetPin_C(LEDC1);
		break;
		case OFF:
		ReSetPin_C(LEDC1);
		break;
		default:
		ReSetPin_C(LEDC1);
	}
}
void _Led2(char state)
{
	switch(state)
	{
		case ON:
		SetPin_D(LEDD2);
		break;
		case OFF:
		ReSetPin_D(LEDD2);
		break;
		default:
		ReSetPin_D(LEDD2);
	}
}