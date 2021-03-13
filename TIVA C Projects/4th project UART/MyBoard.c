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


////////////////// UART /////////////////////// 
/*
	-Their are 8 UART
	-Baud Rate up to 5Mbps for regular speed(divide by 16)
	-Baud Rate up to 10Mbps for high speed(divide by 8)
	
	-Their are 16x8 for each TX & RX FIFOs (Buffers)
	-Programable FIFO length
	- 5, 6, 7, 8 data bits
	-Even, odd, stick, or no parity bit 
	-one or two stop bits
	
	>>UART0 PA0/PA1
	>>UART1 PB0/PB1
	>>UART2 PD6/PD7
	>>UART3 PC6/PC7
	>>UART4 PC4/PC5
	>>UART5 PE4/PE5
	>>UART6 PD4/PD5
	>>UART7 PE0/PE1
	
	//we use 22 bit (16 for integer(UARTIBRD) & 6 for fraction(UARTFBRD)) to select baud rate PRD
	>>>>>>>>>> BRD = IPRD + FPRD = SysClk / (ClkDiv * Baud Rate)
	IPRD = (int part) of BRD
	FPRD = ((Frac part) * 64) + 0.5 of BRD
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
