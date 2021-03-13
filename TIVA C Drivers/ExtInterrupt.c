

#include"ExtInterrupt.h"
#include"tm4c123gh6pm.h"


void ExtINT_InitA(int PinNum,int Type)
{
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= (1<<PinNum);
	GPIO_PORTA_DIR_R &= ~(1 << PinNum);
	GPIO_PORTA_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTA_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTA_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTA_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTA_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTA_IS_R &= ~(1 << PinNum);
		GPIO_PORTA_IBE_R &= ~(1 << PinNum);
		GPIO_PORTA_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTA_IS_R &= ~(1 << PinNum);
		GPIO_PORTA_IBE_R &= ~(1 << PinNum);
		GPIO_PORTA_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTA_IS_R &= ~(1 << PinNum);
		GPIO_PORTA_IBE_R |= (1 << PinNum);
		GPIO_PORTA_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTA_IS_R |= (1 << PinNum);
		GPIO_PORTA_IBE_R &= ~(1 << PinNum);
		GPIO_PORTA_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTA_IS_R |= (1 << PinNum);
		GPIO_PORTA_IBE_R &= ~(1 << PinNum);
		GPIO_PORTA_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTA_IM_R |= (1 << PinNum);
	GPIO_PORTA_DEN_R |= (1 << PinNum);	
}

void ExtINT_InitB(int PinNum,int Type)
{
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= (1<<PinNum);
	GPIO_PORTB_DIR_R &= ~(1 << PinNum);
	GPIO_PORTB_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTB_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTB_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTB_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTB_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTB_IS_R &= ~(1 << PinNum);
		GPIO_PORTB_IBE_R &= ~(1 << PinNum);
		GPIO_PORTB_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTB_IS_R &= ~(1 << PinNum);
		GPIO_PORTB_IBE_R &= ~(1 << PinNum);
		GPIO_PORTB_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTB_IS_R &= ~(1 << PinNum);
		GPIO_PORTB_IBE_R |= (1 << PinNum);
		GPIO_PORTB_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTB_IS_R |= (1 << PinNum);
		GPIO_PORTB_IBE_R &= ~(1 << PinNum);
		GPIO_PORTB_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTB_IS_R |= (1 << PinNum);
		GPIO_PORTB_IBE_R &= ~(1 << PinNum);
		GPIO_PORTB_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTB_IM_R |= (1 << PinNum);
	GPIO_PORTA_DEN_R |= (1 << PinNum);	
}

void ExtINT_InitC(int PinNum,int Type)
{
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= (1<<PinNum);
	GPIO_PORTC_DIR_R &= ~(1 << PinNum);
	GPIO_PORTC_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTC_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTC_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTC_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTC_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTC_IS_R &= ~(1 << PinNum);
		GPIO_PORTC_IBE_R &= ~(1 << PinNum);
		GPIO_PORTC_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTC_IS_R &= ~(1 << PinNum);
		GPIO_PORTC_IBE_R &= ~(1 << PinNum);
		GPIO_PORTC_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTC_IS_R &= ~(1 << PinNum);
		GPIO_PORTC_IBE_R |= (1 << PinNum);
		GPIO_PORTC_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTC_IS_R |= (1 << PinNum);
		GPIO_PORTC_IBE_R &= ~(1 << PinNum);
		GPIO_PORTC_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTC_IS_R |= (1 << PinNum);
		GPIO_PORTC_IBE_R &= ~(1 << PinNum);
		GPIO_PORTC_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTC_IM_R |= (1 << PinNum);
	GPIO_PORTC_DEN_R |= (1 << PinNum);	
}
void ExtINT_InitD(int PinNum,int Type)
{
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R |= (1<<PinNum);
	GPIO_PORTD_DIR_R &= ~(1 << PinNum);
	GPIO_PORTD_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTD_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTD_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTD_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTD_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTD_IS_R &= ~(1 << PinNum);
		GPIO_PORTD_IBE_R &= ~(1 << PinNum);
		GPIO_PORTD_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTD_IS_R &= ~(1 << PinNum);
		GPIO_PORTD_IBE_R &= ~(1 << PinNum);
		GPIO_PORTD_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTD_IS_R &= ~(1 << PinNum);
		GPIO_PORTD_IBE_R |= (1 << PinNum);
		GPIO_PORTD_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTD_IS_R |= (1 << PinNum);
		GPIO_PORTD_IBE_R &= ~(1 << PinNum);
		GPIO_PORTD_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTD_IS_R |= (1 << PinNum);
		GPIO_PORTD_IBE_R &= ~(1 << PinNum);
		GPIO_PORTD_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTD_IM_R |= (1 << PinNum);
	GPIO_PORTD_DEN_R |= (1 << PinNum);	
}
void ExtINT_InitE(int PinNum,int Type)
{
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= (1<<PinNum);
	GPIO_PORTE_DIR_R &= ~(1 << PinNum);
	GPIO_PORTE_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTE_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTE_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTE_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTE_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTE_IS_R &= ~(1 << PinNum);
		GPIO_PORTE_IBE_R &= ~(1 << PinNum);
		GPIO_PORTE_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTE_IS_R &= ~(1 << PinNum);
		GPIO_PORTE_IBE_R &= ~(1 << PinNum);
		GPIO_PORTE_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTE_IS_R &= ~(1 << PinNum);
		GPIO_PORTE_IBE_R |= (1 << PinNum);
		GPIO_PORTE_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTE_IS_R |= (1 << PinNum);
		GPIO_PORTE_IBE_R &= ~(1 << PinNum);
		GPIO_PORTE_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTE_IS_R |= (1 << PinNum);
		GPIO_PORTE_IBE_R &= ~(1 << PinNum);
		GPIO_PORTE_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTE_IM_R |= (1 << PinNum);
	GPIO_PORTE_DEN_R |= (1 << PinNum);	
}
void ExtINT_InitF(int PinNum,int Type)
{
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= (1<<PinNum);
	GPIO_PORTF_DIR_R &= ~(1 << PinNum);
	GPIO_PORTF_AFSEL_R &= ~(1 << PinNum);
	GPIO_PORTF_AMSEL_R &= ~(1 << PinNum);
	GPIO_PORTF_PCTL_R &= ~(0xF << PinNum);
	//GPIO_PORTF_PUR_R |= (1 << PinNum); //to enable enternal pull up res
	//GPIO_PORTF_PDR_R |= (1 << PinNum); //to enable enternal pull down res
		
	if (Type == RisingEdge)
	{
		GPIO_PORTF_IS_R &= ~(1 << PinNum);
		GPIO_PORTF_IBE_R &= ~(1 << PinNum);
		GPIO_PORTF_IEV_R |= (1 << PinNum);
	}
	else if (Type == FallingEdge)
	{
		GPIO_PORTF_IS_R &= ~(1 << PinNum);
		GPIO_PORTF_IBE_R &= ~(1 << PinNum);
		GPIO_PORTF_IEV_R &= ~(1 << PinNum);
	}
	else if (Type == BothEdges)
	{
		GPIO_PORTF_IS_R &= ~(1 << PinNum);
		GPIO_PORTF_IBE_R |= (1 << PinNum);
		GPIO_PORTF_IEV_R &= ~(1 <<PinNum);
	}
	else if (Type == LowLevel)
	{
		GPIO_PORTF_IS_R |= (1 << PinNum);
		GPIO_PORTF_IBE_R &= ~(1 << PinNum);
		GPIO_PORTF_IEV_R &= ~(1<<PinNum);
	}
	else if (Type == HighLevel)
	{
		GPIO_PORTF_IS_R |= (1 << PinNum);
		GPIO_PORTF_IBE_R &= ~(1 << PinNum);
		GPIO_PORTF_IEV_R |= (1<<PinNum);
	}
	else {}
	
	GPIO_PORTF_IM_R |= (1 << PinNum);
	GPIO_PORTF_DEN_R |= (1 << PinNum);	
}



void ExtINT_En(int PORTNum,int Priority)
{
	if ( (PORTNum == INT_A)|(PORTNum == INT_B) |(PORTNum == INT_C) | (PORTNum == INT_D) )
	{
		NVIC_PRI0_R &= ~(0xF << ((8 * PORTNum )+ 4) );
		NVIC_PRI0_R |= (Priority << ( (8*PORTNum) + 5));
	}
	 else if (PORTNum == INT_E)
	{
		NVIC_PRI0_R &= ~(0xF << 4 );
		NVIC_PRI0_R |= (Priority << 5);
	}
	else if (PORTNum == INT_F)
	{
		NVIC_PRI7_R &= ~(0xF << 20);
		NVIC_PRI7_R |= ( Priority << 20);
	}
	else {}
		
	NVIC_EN0_R |= (1 << PORTNum);
}
void ExtINT_Disable(int PORTNum)
{
	NVIC_DIS0_R |= (1 << PORTNum);
}
