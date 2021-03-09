/*
 * TIMER.c
 *
 * Created: 2/6/2021 7:03:16 PM
 *  Author: Arafa
 */ 
#include <avr/io.h>
#include "TIMER.h"

void TIMER0_Enable(int freq)
{
	TCCR0 &= ~((1 << CS01)|(1 << CS02)| (1 << CS00));
	TCCR0 |= freq;
}

void TIMER0_Disable(void)
{
	TCCR0 &= ~((1 << CS01)|(1 << CS02)| (1 << CS00));
}

void TIMER0_InitNormal(void)
{
	TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
	//TIMSK = (1<<TOIE0);
			
}

void TIMER0_InitCTC(char CmpValue,int CmpAction)
{
	TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
	TCCR0 |= (1<<WGM01);
	OCR0  = CmpValue;
	TCCR0 |= (1<<FOC0);
	TCCR0 &= ~((1 << COM00)|(1 << COM01));
	TCCR0 |=(CmpAction << COM00);
	//TIMSK  |= (1 << OCIE0);
}

void TIMER0_InitPWM(int PWMAction)
{
	TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
	TCCR0 |= (1<<WGM00);
	OCR0 = 255;
	TCCR0 &= ~(1<<FOC0);
	TCCR0 &= ~((1 << COM00)|(1 << COM01));
	TCCR0|=(PWMAction << COM00);
//	TIMSK |= (1 << OCIE0);
}

void TIMER0_InitFPWM(int FPWMAction)
{
	TCCR0 |= (1<<WGM01)|(1<<WGM00);
	OCR0 = 255;
	TCCR0 &= ~(1<<FOC0);
	TCCR0 &= ~((1 << COM00)|(1 << COM01));
	TCCR0|=(FPWMAction << COM00);
//	TIMSK |= (1 << OCIE0);
}

void TIMER0_PWMWidth(char PWMValue)
{
	OCR0 = PWMValue;
}

void TIMER0_FPWMWidth(char FPWMValue)
{
	OCR0 = FPWMValue;
}

void TIMER0_IinterruptEnable(int mode)
{
	TIMSK |= (1<< mode);
}

void TIMER0_IinterruptDisable(int mode)
{
	TIMSK  &= ~(1<< mode);
}


void TIMER1_Enable(int freq)
{
	TCCR1B &= ~((1 << CS10)|(1 << CS11)| (1 << CS12));
	TCCR1B |= freq;
}

void TIMER1_Disable(void)
{
	TCCR1B &= ~((1 << CS10)|(1 << CS11)| (1 << CS12));
}

void TIMER1_InitNormal(void)
{
	TCCR1A &= ~((1<<WGM10)|(1<<WGM11));
	TCCR1B &= ~((1<<WGM12)|(1<<WGM13));
	//TIMSK = (1<<TOIE0);
	
}

void TIMER1_InitCTC(int CmpValue,int CmpAction)
{
	TCCR1A &= ~((1<<WGM10)|(1<<WGM11));
	TCCR1B &= ~((1<<WGM12)|(1<<WGM13));
	TCCR1B |= (1<<WGM12);
	OCR1A = CmpValue & 0xFFFF;
	TCCR1A |= (1<<FOC1A);
	TCCR1A &= ~((1 << COM1A0)|(1 << COM1A1));
	TCCR1A |=(CmpAction << COM1A0);
}

void TIMER1_InitFPWM_Fixed(short BitsNum, short DutyCycle ,int FPWMAction)
{
	TCCR1A &= ~((1<<WGM10)|(1<<WGM11));
	TCCR1B &= ~((1<<WGM12)|(1<<WGM13));
	TCCR1A |= BitsNum & 0x03;
	TCCR1B |= ((BitsNum & 0x0C) << 1) ;
	TCCR1A &= ~(1<<FOC1A);
	OCR1A = DutyCycle;
	TCCR1A &= ~((1 << COM1A0)|(1 << COM1A1));
	TCCR1A|=(FPWMAction << COM1A0);
}

void TIMER1_InitFPWM_Cmp(short MaxValue,short dutycycle ,int FPWMAction)
{
	TCCR1A&= ~(1<<WGM10);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= ((1<<WGM12)|(1<<WGM13));
	TCCR1A &= ~(1<<FOC1A);
	ICR1 = MaxValue & 0xFFFF;
	OCR1A = dutycycle;
	TCCR1A &= ~((1 << COM1A0)|(1 << COM1A1));
	TCCR1A|=(FPWMAction << COM1A0);
}

void TIMER1_PWMWidth(short PWMValue)
{
	OCR1A = PWMValue;
}

void TIMER1_FPWMWidth(char FPWMValue)
{
	OCR0 = FPWMValue;
}

void TIMER1_IinterruptEnable(int mode)
{
		TIMSK |= (1<< mode);
}

void TIMER1_IinterruptDisable(int mode)
{
	switch (mode)
	{
		TIMSK  &= ~(1<< mode);
	}
}



void TIMER2_Enable(int freq)
{
	TCCR2 &= ~((1 << CS20)|(1 << CS21)| (1 << CS22));
	TCCR2 |= freq;
}

void TIMER2_Disable(void)
{
	TCCR2 &= ~((1 << CS20)|(1 << CS21)| (1 << CS22));
}

void TIMER2_InitNormal(void)
{
	TCCR2 &= ~((1<<WGM20)|(1<<WGM21));
	
	
}

void TIMER2_InitCTC(char CmpValue,int CmpAction)
{
	TCCR2 &= ~((1<<WGM20)|(1<<WGM21));
	TCCR2 |= (1<<WGM21);
	OCR2  = CmpValue;
	TCCR2 |= (1<<FOC2);
	TCCR2 &= ~((1 << COM20)|(1 << COM21));
	TCCR2 |=(CmpAction << COM20);

}

void TIMER2_InitPWM(int PWMAction)
{
	TCCR2 &= ~((1<<WGM20)|(1<<WGM21));
	TCCR2 |= (1<<WGM20);
	OCR2 = 255;
	TCCR2 &= ~(1<<FOC2);
	TCCR2 &= ~((1 << COM20)|(1 << COM21));
	TCCR2|=(PWMAction << COM20);

}

void TIMER2_InitFPWM(int FPWMAction)
{
	TCCR2 |= (1<<WGM21)|(1<<WGM20);
	OCR2 = 255;
	TCCR2 &= ~(1<<FOC2);
	TCCR2 &= ~((1 << COM20)|(1 << COM21));
	TCCR2|=(FPWMAction << COM20);

}

void TIMER2_PWMWidth(char PWMValue)
{
	OCR2 = PWMValue;
}

void TIMER2_FPWMWidth(char FPWMValue)
{
	OCR2 = FPWMValue;
}

void TIMER2_IinterruptEnable(int mode)
{

	TIMSK |= (1 << mode);

}

void TIMER2_IinterruptDisable(int mode)
{
	TIMSK &= ~(1<< mode);
}

void ServoT2_Init(void)
{
	DDRD |= 1<<7;
	TIMER2_InitPWM(PWM_SetUpClearDown);
	TIMER2_Enable(T2_ClkDiv_1024);
}

void ServoT2_Degree(int degree)
{
	OCR2 = (char)(250-(15*degree/180));
}