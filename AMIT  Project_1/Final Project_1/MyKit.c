/*
 * MyKit.c
 *
 * Created: 1/9/2021 6:39:39 PM
 *  Author: Arafa
 */ 
#include "MyKit.h"
#include "GPIO.h"

void BzrInit(void)
{
	Dir_A(out_pin,BzrPinA);
}
void _BzrA3(char state)
{
	switch (state)
	{
		case ON:
		SetPin_A(BzrPinA);
		break;
		case OFF:
		ReSetPin_A(BzrPinA);
		break;
		default:
		ReSetPin_A(BzrPinA);
	}
	
}

void Btn0_Init(void)
{
	Dir_B(in_pin , 0);
}
void Btn1_Init(void)
{
	Dir_D(in_pin, 6);
}
void Btn2_Init(void)
{
	Dir_D(in_pin ,2);
}
int IsPressed_Btn0(void)
{
	if (IsPressed_B(BtnB0))
	return 1;
	else
	return 0;
}
int IsPressed_Btn1(void)
{
	if (IsPressed_D(BtnD1))
	return 1;
	else
	return 0;
}
int IsPressed_Btn2(void)
{
	if (IsPressed_D(BtnD2))
	return 1;
	else
	return 0;
}


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


void RelayInit(void)
{
	Dir_A(out_pin,RelayPinA);
}

void _Relay(char state)
{
	switch (state)
	{
		case ON:
		SetPin_A(RelayPinA);
		break;
		case OFF:
		ReSetPin_A(RelayPinA);
		break;
		default:
		ReSetPin_A(RelayPinA);
	}
}