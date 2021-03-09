/*
 * MyKit.h
 *
 * Created: 1/8/2021 7:20:48 PM
 *  Author: Arafa
 */ 

#include <avr/io.h>
#ifndef MYKIT_H_
#define MYKIT_H_

#define BtnB0 0
#define BtnD1 6
#define BtnD2 2

#define  LEDD2 3
#define  LEDC0 2
#define  LEDC1 7

#define RelayPinA 2
#define BzrPinA   3

#define out_pin 1
#define in_pin  0

#define in_Port  0
#define out_Port 1

#define ON  1
#define OFF 0


#define F_CPU 16000000UL


void BzrInit(void);
void _BzrA3(char state);


void Btn0_Init(void);
void Btn1_Init(void);
void Btn2_Init(void);
int IsPressed_Btn0(void);
int IsPressed_Btn1(void);
int IsPressed_Btn2(void);

void LEDInit(void);
void _Led0(char state);
void _Led1(char state);
void _Led2(char state);


void RelayInit(void);
void _Relay(char state);

#endif /* MYKIT_H_ */