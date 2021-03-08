


#include"tm4c123gh6pm.h"
#include"MyBoard.h"
#include"GPIO.h"

volatile unsigned int delay;
void GPIO_Init(char PORT)
{
	SYSCTL_RCGC2_R |=( 1<<PORT );
	delay = SYSCTL_RCGC2_R;	
}

void Dir_PinA(int PinNum, char state)
{
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= (1<<PinNum); 
	if (state == in_Pin)
	{
		GPIO_PORTA_DIR_R &= ~(1 << PinNum);
		GPIO_PORTA_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTA_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTA_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTA_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTA_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTA_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTA_DIR_R |= (1 << PinNum);
		GPIO_PORTA_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTA_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTA_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTA_DR8R_R |= (1 << PinNum);
	//GPIO_PORTA_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTA_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTA_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTA_DEN_R |= (1 << PinNum);
	}
			
}
void Dir_PinB(int PinNum, char state)
{
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= (1<<PinNum); 
	
	if (state == in_Pin)
	{
		GPIO_PORTB_DIR_R &= ~(1 << PinNum);
		GPIO_PORTB_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTB_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTB_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTB_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTB_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTB_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTB_DIR_R |= (1 << PinNum);
		GPIO_PORTB_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTB_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTB_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTB_DR8R_R |= (1 << PinNum);
	//GPIO_PORTB_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTB_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTB_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTB_DEN_R |= (1 << PinNum);
	}
}

void Dir_PinC(int PinNum, char state)
{
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= (1<<PinNum);
		if (state == in_Pin)
	{
		GPIO_PORTC_DIR_R &= ~(1 << PinNum);
		GPIO_PORTC_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTC_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTC_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTC_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTC_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTC_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTC_DIR_R |= (1 << PinNum);
		GPIO_PORTC_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTC_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTC_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTC_DR8R_R |= (1 << PinNum);
	//GPIO_PORTC_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTC_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTC_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTC_DEN_R |= (1 << PinNum);
	}
}
void Dir_PinD(int PinNum, char state)
{
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= (1<<PinNum);
		if (state == in_Pin)
	{
		GPIO_PORTD_DIR_R &= ~(1 << PinNum);
		GPIO_PORTD_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTD_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTD_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTD_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTD_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTD_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTD_DIR_R |= (1 << PinNum);
		GPIO_PORTD_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTD_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTD_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTD_DR8R_R |= (1 << PinNum);
	//GPIO_PORTD_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTD_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTD_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTD_DEN_R |= (1 << PinNum);
	}
}
void Dir_PinE(int PinNum, char state)
{
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= (1<<PinNum);
		if (state == in_Pin)
	{
		GPIO_PORTE_DIR_R &= ~(1 << PinNum);
		GPIO_PORTE_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTE_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTE_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTE_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTE_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTE_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTE_DIR_R |= (1 << PinNum);
		GPIO_PORTE_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTE_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTE_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTE_DR8R_R |= (1 << PinNum);
	//GPIO_PORTE_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTE_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTE_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTE_DEN_R |= (1 << PinNum);
	}
}
void Dir_PinF(int PinNum, char state)
{
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= (1<<PinNum);
		if (state == in_Pin)
	{
		GPIO_PORTF_DIR_R &= ~(1 << PinNum);
		GPIO_PORTF_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTF_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTF_PCTL_R &= ~(0xF << PinNum);
		GPIO_PORTF_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTF_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		GPIO_PORTF_DEN_R |= (1 << PinNum);
	}
	else if(state == out_Pin)
	{
		GPIO_PORTF_DIR_R |= (1 << PinNum);
		GPIO_PORTF_AFSEL_R &= ~(1 << PinNum);
		GPIO_PORTF_AMSEL_R &= ~(1 << PinNum);
		GPIO_PORTF_PCTL_R &= ~(0xF << (PinNum*4));
		GPIO_PORTF_DR8R_R |= (1 << PinNum);
	//GPIO_PORTF_DR4R_R |= (1 << PinNum); //for 4-mA 
	//GPIO_PORTF_DR2R_R |= (1 << PinNum); //for 2-mA
	//GPIO_PORTF_ODR_R |= (1 << PinNum);  //for open drain Fn 
		GPIO_PORTF_DEN_R |= (1 << PinNum);
	}
}

void Dir_LPORTA(char state)
{
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTA_DIR_R &= ~0x0F;
		GPIO_PORTA_AFSEL_R &= ~0x0F;
		GPIO_PORTA_AMSEL_R &= ~0x0F;
		GPIO_PORTA_PCTL_R &= ~0xFFFF;
	//GPIO_PORTA_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTA_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTA_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTA_DIR_R |= 0x0F;
		GPIO_PORTA_AFSEL_R &= ~0x0F;
		GPIO_PORTA_AMSEL_R &= ~0x0F;
		GPIO_PORTA_PCTL_R &= ~0xFFFF;
		GPIO_PORTA_DR8R_R |= 0x0F;
	//GPIO_PORTA_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTA_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTA_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTA_DEN_R |= 0x0F;
	}
	else{}
}

void Dir_HPORTA(char state)
{
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xF0; 
	if (state == in_Pin)
	{
		GPIO_PORTA_DIR_R &= ~0xF0;
		GPIO_PORTA_AFSEL_R &= ~0xF0;
		GPIO_PORTA_AMSEL_R &= ~0xF0;
		GPIO_PORTA_PCTL_R &= ~0xFFFF0000;
	//GPIO_PORTA_PUR_R |= 0xF0; //to enable enternal pull up res
	//GPIO_PORTA_PDR_R |= 0xF0; //to enable enternal pull down res
		GPIO_PORTA_DEN_R |= 0xF0;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTA_DIR_R |= 0xF0;
		GPIO_PORTA_AFSEL_R &= ~0xF0;
		GPIO_PORTA_AMSEL_R &= ~0xF0;
		GPIO_PORTA_PCTL_R &= ~0xFFFF0000;
		GPIO_PORTA_DR8R_R |= 0xF0;
	//GPIO_PORTA_DR4R_R |= 0xF0; //for 4-mA 
	//GPIO_PORTA_DR2R_R |= 0xF0; //for 2-mA
	//GPIO_PORTA_ODR_R |= 0xF0;  //for open drain Fn 
		GPIO_PORTA_DEN_R |= 0xF0;
	}
	else{}
}

void Dir_LPORTB(char state)
{
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTB_DIR_R &= ~0x0F;
		GPIO_PORTB_AFSEL_R &= ~0x0F;
		GPIO_PORTB_AMSEL_R &= ~0x0F;
		GPIO_PORTB_PCTL_R &= ~0xFFFF;
	//GPIO_PORTB_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTB_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTB_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTB_DIR_R |= 0x0F;
		GPIO_PORTB_AFSEL_R &= ~0x0F;
		GPIO_PORTB_AMSEL_R &= ~0x0F;
		GPIO_PORTB_PCTL_R &= ~0xFFFF;
		GPIO_PORTB_DR8R_R |= 0x0F;
	//GPIO_PORTB_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTB_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTB_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTB_DEN_R |= 0x0F;
	}
	else{}
}

void Dir_HPORTB(char state)
{
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xF0; 
	if (state == in_Pin)
	{
		GPIO_PORTB_DIR_R &= ~0xF0;
		GPIO_PORTB_AFSEL_R &= ~0xF0;
		GPIO_PORTB_AMSEL_R &= ~0xF0;
		GPIO_PORTB_PCTL_R &= ~0xFFFF0000;
	//GPIO_PORTB_PUR_R |= 0xF0; //to enable enternal pull up res
	//GPIO_PORTB_PDR_R |= 0xF0; //to enable enternal pull down res
		GPIO_PORTB_DEN_R |= 0xF0;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTB_DIR_R |= 0xF0;
		GPIO_PORTB_AFSEL_R &= ~0xF0;
		GPIO_PORTB_AMSEL_R &= ~0xF0;
		GPIO_PORTB_PCTL_R &= ~0xFFFF0000;
		GPIO_PORTB_DR8R_R |= 0xF0;
	//GPIO_PORTB_DR4R_R |= 0xF0; //for 4-mA 
	//GPIO_PORTB_DR2R_R |= 0xF0; //for 2-mA
	//GPIO_PORTB_ODR_R |= 0xF0;  //for open drain Fn 
		GPIO_PORTB_DEN_R |= 0xF0;
	}
	else{}
}

void Dir_LPORTC(char state)
{
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTC_DIR_R &= ~0x0F;
		GPIO_PORTC_AFSEL_R &= ~0x0F;
		GPIO_PORTC_AMSEL_R &= ~0x0F;
		GPIO_PORTC_PCTL_R &= ~0xFFFF;
	//GPIO_PORTC_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTC_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTC_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTC_DIR_R |= 0x0F;
		GPIO_PORTC_AFSEL_R &= ~0x0F;
		GPIO_PORTC_AMSEL_R &= ~0x0F;
		GPIO_PORTC_PCTL_R &= ~0xFFFF;
		GPIO_PORTC_DR8R_R |= 0x0F;
	//GPIO_PORTC_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTC_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTC_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTC_DEN_R |= 0x0F;
	}
	else{}
}

void Dir_HPORTC(char state)
{
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= 0xF0; 
	if (state == in_Pin)
	{
		GPIO_PORTC_DIR_R &= ~0xF0;
		GPIO_PORTC_AFSEL_R &= ~0xF0;
		GPIO_PORTC_AMSEL_R &= ~0xF0;
		GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	//GPIO_PORTC_PUR_R |= 0xF0; //to enable enternal pull up res
	//GPIO_PORTC_PDR_R |= 0xF0; //to enable enternal pull down res
		GPIO_PORTC_DEN_R |= 0xF0;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTC_DIR_R |= 0xF0;
		GPIO_PORTC_AFSEL_R &= ~0xF0;
		GPIO_PORTC_AMSEL_R &= ~0xF0;
		GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
		GPIO_PORTC_DR8R_R |= 0xF0;
	//GPIO_PORTC_DR4R_R |= 0xF0; //for 4-mA 
	//GPIO_PORTC_DR2R_R |= 0xF0; //for 2-mA
	//GPIO_PORTC_ODR_R |= 0xF0;  //for open drain Fn 
		GPIO_PORTC_DEN_R |= 0xF0;
	}
	else{}
}

void Dir_LPORTD(char state)
{
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTD_DIR_R &= ~0x0F;
		GPIO_PORTD_AFSEL_R &= ~0x0F;
		GPIO_PORTD_AMSEL_R &= ~0x0F;
		GPIO_PORTD_PCTL_R &= ~0xFFFF;
	//GPIO_PORTD_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTD_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTD_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTD_DIR_R |= 0x0F;
		GPIO_PORTD_AFSEL_R &= ~0x0F;
		GPIO_PORTD_AMSEL_R &= ~0x0F;
		GPIO_PORTD_PCTL_R &= ~0xFFFF;
		GPIO_PORTD_DR8R_R |= 0x0F;
	//GPIO_PORTD_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTD_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTD_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTD_DEN_R |= 0x0F;
	}
	else{}
}

void Dir_HPORTD(char state)
{
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= 0xF0; 
	if (state == in_Pin)
	{
		GPIO_PORTD_DIR_R &= ~0xF0;
		GPIO_PORTD_AFSEL_R &= ~0xF0;
		GPIO_PORTD_AMSEL_R &= ~0xF0;
		GPIO_PORTD_PCTL_R &= ~0xFFFF0000;
	//GPIO_PORTD_PUR_R |= 0xF0; //to enable enternal pull up res
	//GPIO_PORTD_PDR_R |= 0xF0; //to enable enternal pull down res
		GPIO_PORTD_DEN_R |= 0xF0;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTD_DIR_R |= 0xF0;
		GPIO_PORTD_AFSEL_R &= ~0xF0;
		GPIO_PORTD_AMSEL_R &= ~0xF0;
		GPIO_PORTD_PCTL_R &= ~0xFFFF0000;
		GPIO_PORTD_DR8R_R |= 0xF0;
	//GPIO_PORTD_DR4R_R |= 0xF0; //for 4-mA 
	//GPIO_PORTD_DR2R_R |= 0xF0; //for 2-mA
	//GPIO_PORTD_ODR_R |= 0xF0;  //for open drain Fn 
		GPIO_PORTD_DEN_R |= 0xF0;
	}
	else{}
}

void Dir_LPORTE(char state)
{
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTE_DIR_R &= ~0x0F;
		GPIO_PORTE_AFSEL_R &= ~0x0F;
		GPIO_PORTE_AMSEL_R &= ~0x0F;
		GPIO_PORTE_PCTL_R &= ~0xFFFF;
	//GPIO_PORTE_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTE_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTE_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTE_DIR_R |= 0x0F;
		GPIO_PORTE_AFSEL_R &= ~0x0F;
		GPIO_PORTE_AMSEL_R &= ~0x0F;
		GPIO_PORTE_PCTL_R &= ~0xFFFF;
		GPIO_PORTE_DR8R_R |= 0x0F;
	//GPIO_PORTE_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTE_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTE_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTE_DEN_R |= 0x0F;
	}
	else{}
}
void Dir_LPORTF(char state)
{
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x0F; 
	if (state == in_Pin)
	{
		GPIO_PORTF_DIR_R &= ~0x0F;
		GPIO_PORTF_AFSEL_R &= ~0x0F;
		GPIO_PORTF_AMSEL_R &= ~0x0F;
		GPIO_PORTF_PCTL_R &= ~0xFFFF;
	//GPIO_PORTF_PUR_R |= 0x0F; //to enable enternal pull up res
	//GPIO_PORTF_PDR_R |= 0x0F; //to enable enternal pull down res
		GPIO_PORTF_DEN_R |= 0x0F;
	}
	else if(state == out_Pin)
	{
		GPIO_PORTF_DIR_R |= 0x0F;
		GPIO_PORTF_AFSEL_R &= ~0x0F;
		GPIO_PORTF_AMSEL_R &= ~0x0F;
		GPIO_PORTF_PCTL_R &= ~0xFFFF;
		GPIO_PORTF_DR8R_R |= 0x0F;
	//GPIO_PORTF_DR4R_R |= 0x0F; //for 4-mA 
	//GPIO_PORTF_DR2R_R |= 0x0F; //for 2-mA
	//GPIO_PORTF_ODR_R |= 0x0F;  //for open drain Fn 
		GPIO_PORTF_DEN_R |= 0x0F;
	}
	else{}
}


void Set_PinA(int PinNum)
{
	GPIO_PORTA_DATA_R |= (1<<PinNum);
}
void Set_PinB(int PinNum)
{
	GPIO_PORTB_DATA_R |= (1<<PinNum);
}
void Set_PinC(int PinNum)
{
	GPIO_PORTC_DATA_R |= (1<<PinNum);
}
void Set_PinD(int PinNum)
{
	GPIO_PORTD_DATA_R |= (1<<PinNum);
}
void Set_PinE(int PinNum)
{
	GPIO_PORTE_DATA_R |= (1<<PinNum);
}
void Set_PinF(int PinNum)
{
	GPIO_PORTF_DATA_R |= (1<<PinNum);
}


void Toggle_PinA(int PinNum)
{
	GPIO_PORTA_DATA_R ^= (1<<PinNum);
}
void Toggle_PinB(int PinNum)
{
	GPIO_PORTB_DATA_R ^= (1<<PinNum);
}
void Toggle_PinC(int PinNum)
{
	GPIO_PORTC_DATA_R ^= (1<<PinNum);
}
void Toggle_PinD(int PinNum)
{
	GPIO_PORTD_DATA_R ^= (1<<PinNum);
}
void Toggle_PinE(int PinNum)
{
	GPIO_PORTE_DATA_R ^= (1<<PinNum);
}
void Toggle_PinF(int PinNum)
{
	GPIO_PORTF_DATA_R ^= (1<<PinNum);
}


void Reset_PinA(int PinNum)
{
	GPIO_PORTA_DATA_R &= ~(1<<PinNum);
}
void Reset_PinB(int PinNum)
{
	GPIO_PORTB_DATA_R &= ~(1<<PinNum);
}
void Reset_PinC(int PinNum)
{
	GPIO_PORTC_DATA_R &= ~(1<<PinNum);
}
void Reset_PinD(int PinNum)
{
	GPIO_PORTD_DATA_R &= ~(1<<PinNum);
}
void Reset_PinE(int PinNum)
{
	GPIO_PORTE_DATA_R &= ~(1 << PinNum);
}
void Reset_PinF(int PinNum)
{
	GPIO_PORTF_DATA_R &= ~(1<<PinNum);
}


int Read_PinA(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTA_DATA_R & (1<<PinNum) )== 0 ? 1: 0 );
	else if(state == HIGH )
		return ( (GPIO_PORTA_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}

int Read_PinB(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTB_DATA_R & (1<<PinNum) )== 0 ? 1: 0 );
	else if(state == HIGH )
		return ( (GPIO_PORTB_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}
int Read_PinC(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTC_DATA_R & (1<<PinNum) )== 0 ? 1: 0 );
	else if(state == HIGH )
		return ( (GPIO_PORTC_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}
int Read_PinD(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTD_DATA_R & (1<<PinNum) )== 0 ? 1: 0 );
	else if(state == HIGH )
		return ( (GPIO_PORTD_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}
int Read_PinE(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTE_DATA_R & (1<<PinNum) )== 0 ? 1: 0 );
	else if(state == HIGH )
		return ( (GPIO_PORTE_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}
int Read_PinF(int PinNum,char state)
{
	if (state == LOW)
		return ( (GPIO_PORTF_DATA_R & (1<<PinNum) ) ? 0: 1 );
	else if(state == HIGH )
		return ( (GPIO_PORTF_DATA_R & (1<<PinNum) )? 1: 0 );
	else{return 0;}
}
