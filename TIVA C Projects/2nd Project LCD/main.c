#include"tm4c123gh6pm.h"
#include"GPIO.h"
#include"MyBoard.h"
#include"LCD4.h"



int  main()
{
	
	LCD4_Init();
	LCD4_Data('A');
	delay_ms(2000);
	LCD4_Clear();
	LCD4_IntData(-12345);
	delay_ms(2000);
	LCD4_Clear();
	LCD4_StrData("Arafa");
	while(1)
	{
	}
}


void SystemInit(void)
{
}
