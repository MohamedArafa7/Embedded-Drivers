#include"tm4c123gh6pm.h"
#include"GPIO.h"
#include"MyBoard.h"
#include"ExtInterrupt.h"

void EnableInterrupts(void);
void WaitForInterrupt(void);

void GPIOPortF_Handler(void){
  GPIO_PORTF_ICR_R |= 0x01;      // acknowledge flag4
  Toggle_PinF(LED_RedF);
}
int  main()
{
	GPIO_Init(PORTF);
	Dir_PinF(LED_RedF,out_Pin);
	Reset_PinF(LED_RedF);
	
	ExtINT_InitF(0,FallingEdge);
	ExtINT_En(INT_F,5);
	
	/*Dir_PinF(Btn2F,in_Pin);
	Dir_PinF(LED_RedF,out_Pin);
	Dir_PinF(Btn1F,in_Pin);
	Dir_PinF(LED_GreenF,out_Pin);*/
	
	 EnableInterrupts();
	
	while(1)
	{
		WaitForInterrupt();
		/*if(Read_PinF(Btn2F,LOW))
			Set_PinF(LED_RedF);
		else
			Reset_PinF(LED_RedF);
		
		if(Read_PinF(Btn1F,LOW))
			Set_PinF(LED_GreenF);
		else
			Reset_PinF(LED_GreenF);*/
	}
}


void SystemInit(void)
{
}
