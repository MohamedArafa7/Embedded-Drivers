/*
 * 1St project GPIO.c
 *
 * Created: 1/2/2021 8:22:40 PM
 * Author : Arafa
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	
	
	DDRA = 0XFF;     /// PortA as output
	
	PORTA = 0x00;   ///PortA all pins are high
	
    while (1) 
    {
			for (int i = 7; i >= 1;i--)
			{
				_delay_ms(500);
				PORTA = (1<<i);
			}
		for (int i = 0; i < 7;i++)
		{
			_delay_ms(500);
			PORTA = (1<<i);
		}
	
		
		
    }
}

