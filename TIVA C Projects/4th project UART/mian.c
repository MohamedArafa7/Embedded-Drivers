#include "tm4c123gh6pm.h"
#include "UART.h"
#include "MyBoard.h"
#include "GPIO.h"

void EnableInterrupts(void);
void WaitForInterrupt(void);
void DisableInterrupts(void);


void UART1_Handler(void)
{
	
	char RXData;
		RXData = UART1_DR_R;
		if(RXData == 'A')
		{
			Set_PinF(3);
			//GPIO_PORTF_DATA_R |= (1 << 1);
		}
		else if(RXData == 'B')
		{
			Reset_PinF(3);
			//GPIO_PORTF_DATA_R &= ~(1 << 1);
			
		}
		else{}
	
		UART1_ICR_R |=(1 << 4); 
}

int main()
{
	GPIO_Init(PORTF);
	Dir_PinF(3,out_Pin);
	Set_PinF(3);
	UART1_Init(9600,UART_8Bits);
	UART1_InterruptEnable(5);
	UART1_Enable();
	
	EnableInterrupts();
	while(1)
	{
		UART1_Data('A');
		delay_ms(1000);
		UART1_Data('B');
		delay_ms(1000);
	}
}
