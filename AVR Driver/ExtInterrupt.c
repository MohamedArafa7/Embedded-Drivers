/*
 * ExtInterrupt.c
 *
 * Created: 1/16/2021 9:07:39 PM
 *  Author: Arafa
 */ 

#include <avr/io.h>
#include "ExtInterrupt.h"

void ExtINT0_Init(int INTsenseControl)
{
	 // sense control mode
	 MCUSR |=(INTsenseControl << ISC00);
	 
	 //interrupt Enable
	 GICR |= (1<<INT0); 	
}
void ExtINT1_Init(int INTsenseControl)
{
	// sense control mode
	MCUSR |=(INTsenseControl << ISC10);
	
	//interrupt Enable
	GICR |= (1<<INT1);
}

void ExtINT2_Init(int INTsenseControl)
{
	// sense control mode
	if (INTsenseControl == FallingEdge)
	{
		MCUCSR &=~(1<< ISC2);
	}
	else if (INTsenseControl == RisingEdge)
	{
		MCUCSR |=(1<< ISC2);
	}
	else
	{
		
	}
	
	//interrupt Enable
	GICR |= (1<<INT2);
}


void  ExtINT_disable(int INTnumber)
{
	GICR &= ~(1<<INTnumber);
}