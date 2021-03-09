/*
 * Bzr.c
 *
 * Created: 1/9/2021 1:31:20 PM
 *  Author: Arafa
 */ 

#include "GPIO.h"
#include "MyKit.h"


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