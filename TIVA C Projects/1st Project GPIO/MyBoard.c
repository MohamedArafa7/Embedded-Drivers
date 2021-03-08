#include"tm4c123gh6pm.h"
#include"MyBoard.h"

// Bins of board are 
/*
	PORTA 0:7  8 pins
	PORTB 0:7  8 pins
	PORTC 0:7  8 pins
	PORTD 0:7  8 pins
	PORTE 0:5  6 pins
	PORTF 0:4  5 pins
*/

/// For input voltage MAX tolerant 
/*
	PD4, PD5, PB0, and PB1  >> 3.6V max
	other Pins >> 5V max
*/


/// defult alternative Fn for some pins
/*
	PA0:1 UART0 GPIO_PCTL 0x1
	PA2:5 SPI0  GPIO_PCTL 0x2
	PB2:3 I2C0  GPIO_PCTL 0x3
	PC0:3 JTAG/SWD   AFSEL DEN PUR PCTL 0x1
*/


/// Locked Pins
/*
	PC0:3
	PD7
	PF0
*/
void delay_ms(int ms)
{
	int i, j = 0;
	for(i = 0; i < ms; i++)
	{
		for(j = 0; j <2802 ;j++)
		{}
	}
}
