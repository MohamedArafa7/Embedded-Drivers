/*
 * Btn.c
 *
 * Created: 1/9/2021 11:44:33 AM
 *  Author: Arafa
 */ 
#include "MyKit.h"
#include "GPIO.h"

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