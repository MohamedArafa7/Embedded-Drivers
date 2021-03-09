/*
* 2nd project GPIO.c
*
* Created: 1/8/2021 6:37:37 PM
* Author : Arafa
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "GPIO.h"
#include "MyKit.h"
#include "LEDs.h"
#include "Relay.h"
#include "Btn.h"
#include "Bzr.h"

/*
int main(void)
{
// Replace with your application code
//DDRA = 0xff;   // PORTA as OUTPUT
//PORTA = 0x00;   // Drive LOW to PORTA
DDRD |= 1<<LED2;
DDRC = 0x00;  // PORTC as INPUT

while (1)
{
if (IsPressed_D(Btn2)) /// cheek the PIN 0 in PORTC
{
PORTD |= 1<<LED2;   // Set ALL PORTA
}
else
{
PORTD &= ~(1<<LED2) ;   // Reset ALL PORTA
}

}
}
*/


/*int main(void)
{
	LEDInit();
	
	
	while (1)
	{
		_Led0(ON);
		_delay_ms(500);
		_Led0(OFF);
		_Led1(ON);
		_delay_ms(500);
		_Led1(OFF);
		_Led2(ON);
		_delay_ms(500);
		_Led2(OFF);
		_Led1(ON);
		_delay_ms(500);
		_Led1(OFF);
	}
	
}
*/


int main(void)
{
	LEDInit();
	RelayInit();
	BzrInit();
	
	Btn0_Init();
	Btn1_Init();
	Btn2_Init();
	
	while(1)
	{
		if (IsPressed_Btn0())
		{
			
			_Led0(ON);
			_Relay(ON);
			_BzrA3(OFF);
		}
		else
		{
			_Led0(OFF);
		}
		
		if (IsPressed_Btn1())
		{
			_Led1(ON);
			_Relay(OFF);
			_BzrA3(ON);
		}
		else
		{
			_Led1(OFF);
		}
		if (IsPressed_Btn2())
		{
			_Led2(ON);
			_Relay(ON);
			_BzrA3(OFF);
		}
		else
		{
			_Led2(OFF);
		}
	}
}