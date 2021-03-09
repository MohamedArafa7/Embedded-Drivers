/*
 * Relay.c
 *
 * Created: 1/9/2021 11:29:25 AM
 *  Author: Arafa
 */ 

#include "GPIO.h"
#include "MyKit.h"




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