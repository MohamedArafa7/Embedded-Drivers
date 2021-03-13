/*
 * 5th Project GPIO interrupt.c
 *
 * Created: 1/16/2021 9:06:07 PM
 * Author : Arafa
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ExtInterrupt.h"
#include "GPIO.h"
#include "MyKit.h"

ISR(INT1_vect)
{
	PORTA ^= 0xFF; 
}
int main(void)
{
    /* Replace with your application code */
	Config_A(out_Port);
	PORTA = 0;
	
	ExtINT_disable(INT1);
	ExtINT1_Init(FallingEdge);
	sei();
    while (1) 
    {
    }
}

