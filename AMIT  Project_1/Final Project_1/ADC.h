/*
 * ADC.h
 *
 * Created: 2/5/2021 6:44:07 PM
 *  Author: Arafa
 */ 


#ifndef ADC_H_
#define ADC_H_

#define AREF 0
#define AVCC 1
#define INTERNAL_REF 2

#define CLKDIV_2 1
#define CLKDIV_4 2
#define CLKDIV_8 3
#define CLKDIV_16 4
#define CLKDIV_32 5
#define CLKDIV_64 6
#define CLKDIV_128 7

enum ADC_ch {
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7};



void ADC_Init(int Ref,int channel,int CLK);
void ADC_Ref (int ref);
void ADC_CLK(int PreScaller);
void ADC_Channel(int channel);
int ADC_Read_R();
int ADC_Read_L();
void ADC_Start();
void ADC_WaitCovirsion();



#endif /* ADC_H_ */