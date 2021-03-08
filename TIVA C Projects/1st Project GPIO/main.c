#include"tm4c123gh6pm.h"
#include"GPIO.h"
#include"MyBoard.h"



int  main()
{
	GPIO_Init(PORTF);
	Dir_PinF(Btn2F,in_Pin);
	Dir_PinF(LED_RedF,out_Pin);
	Dir_PinF(Btn1F,in_Pin);
	Dir_PinF(LED_GreenF,out_Pin);
	
	
	
	while(1)
	{
		if(Read_PinF(Btn2F,LOW))
			Set_PinF(LED_RedF);
		else
			Reset_PinF(LED_RedF);
		
		if(Read_PinF(Btn1F,LOW))
			Set_PinF(LED_GreenF);
		else
			Reset_PinF(LED_GreenF);
	}
}


void SystemInit(void)
{
}
