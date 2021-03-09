/*
* SPI.c
*
* Created: 2/13/2021 7:15:18 PM
*  Author: Arafa
*/

#include "GPIO.h"
#include "MyKit.h"
#include <avr/io.h>
#include "SPI.h"


void SPI_Init(int Mode, int clk)
{
	SPCR &=~((1<<SPR0)|(1<<SPR1)); //clear these bits to config the clock in the lines below 
	SPSR &= ~(1<<SPI2X); // clear the double speed option until we need it
	
	if (clk < 4) // Cheek the clock speed .. if we don't need double speed option
	{
		SPCR |= clk; // Set the desired clock rate
	}
	else
	{
		SPCR |= (clk & 0x3); // Set the desired clock rate and we double it next line 
		SPSR |= ((clk >> 2) & 0x1); // Enable double speed option
	}
	
	switch (Mode) // Cheek the mode user need
	{
		case Master: // For MASTER mode
				SPCR |= (1 << MSTR); //Enable master mode
				
				DDRB |= (1 << MOSI); // Config master out slave in pin to output 
				DDRB &= ~(1<<MISO);  // Config master in slave out pin to input
				DDRB |= (1<<SS);  // Config slave select pin as output
				DDRB |= (1<<SCK); // Config  Serial Clock pin as output
		break;
		
		case Slave:
				SPCR &= ~(1<<MSTR); //Disable master mode
				
				DDRB &=~(1<<MOSI); // Config master out slave in pin to input
				DDRB |= (1<<MISO); // Config master in slave out pin to output
				DDRB &= ~(1<<SS);  // Config slave select pin as input
				DDRB &= ~(1<<SCK); // Config  Serial Clock pin as input
		break;
		
		default:
		break;
	}
	
}

void SPI_ChangeMode(int mode)
{
	SPI_Disable();
	switch (mode) // Cheek the mode user need
	{
		case Master: // For MASTER mode
		SPCR |= (1 << MSTR); //Enable master mode
		
		DDRB |= (1 << MOSI); // Config master out slave in pin to output
		DDRB &= ~(1<<MISO);  // Config master in slave out pin to input
		DDRB |= (1<<SS);  // Config slave select pin as output
		DDRB |= (1<<SCK); // Config  Serial Clock pin as output
		break;
		
		case Slave:
		SPCR &= ~(1<<MSTR); //Disable master mode
		
		DDRB &=~(1<<MOSI); // Config master out slave in pin to input
		DDRB |= (1<<MISO); // Config master in slave out pin to output
		DDRB &= ~(1<<SS);  // Config slave select pin as input
		DDRB &= ~(1<<SCK); // Config  Serial Clock pin as input
		break;
		
		default://do nothing
		break;
	}
	SPI_Enable();
	
}

void SPI_Store(int Store)
{
	SPCR &= ~(1 << DORD); // Clear data order to config it next line
	SPCR |= (1 << Store); // config if LSB is sent/store first DORD = 1 or MSB is sent/store First DORD = 0
}
void SPI_Enable(void)
{
	SPCR |= (1 << SPE); // Enable SPI module
}
void SPI_Disable(void)
{
	SPCR &= ~(1 << SPE); //Disable SPI module 
}
char SPI_Read(void)
{
	return SPDR; // Return received data
	
}
void SPI_Data(char data)
{
	SPDR = data; // Put The data in Data register to send it
	while(!(SPSR & (1 << SPIF))); // wait until all data out
	//SPSR  & = 1 << SPIF;
	//PORTD = 0;
	
}
void SPI_Interrupt_Enable(void)
{
	SPCR |= (1 << SPIE); //Enable interrupts for SPI
}
void SPI_Interrupt_Disable(void)
{
	SPCR &= ~(1 << SPIE); // Disable interrupts for SPI
}