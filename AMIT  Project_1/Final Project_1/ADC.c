/*
 * ADC.c
 *
 * Created: 2/5/2021 6:32:01 PM
 *  Author: Arafa
 */ 


#include <avr/io.h>
#include "ADC.h"


void ADC_Init(int Ref,int channel,int CLK)
{
	ADC_Ref(Ref);
	ADC_CLK(CLK);
	ADC_Channel(ADC0);
	//ADMUX | = (1 <<ADLAR); //for left adjusted 
	ADCSRA |= (1<<ADEN);
}


void ADC_Ref (int ref)
{
	switch(ref)
	{
		case AREF:
			ADMUX &=~((1<<REFS0) | (1<<REFS1)); 
			break;
		case AVCC:
			ADMUX &=~( (1<<REFS0) | (1<<REFS1) );
			ADMUX |= (1<<REFS0);
			break;
		case INTERNAL_REF:
			ADMUX |= (1<<REFS0)|(1<<REFS1);
			break;
		default:
			break;
	}
}

void ADC_CLK(int PreScaller)
{
	ADCSRA = ADCSRA & 0xF8;
	ADCSRA |= PreScaller;
}

void ADC_Channel(int channel)
{
	ADMUX = ADMUX & 0XE0;
	ADMUX |= channel;
}

int ADC_Read_R()
{
	int result = ADCL;
	result |=(ADCH << 8);
	
	return result; 
}

int ADC_Read_L()
{
	int result = (ADCL >> 6);
	result |=(ADCH << 2);
	
	return result;
}

void ADC_Start()
{
	ADCSRA |= (1 << ADSC);
}

void ADC_WaitCovirsion()
{
	while (!(ADCSRA & (1 << ADIF) ));
}