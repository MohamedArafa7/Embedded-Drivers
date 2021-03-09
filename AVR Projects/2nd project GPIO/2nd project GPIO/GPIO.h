/*
 * GPIO.h
 *
 * Created: 1/8/2021 7:05:41 PM
 *  Author: Arafa
 */ 


#ifndef GPIO_H_
#define GPIO_H_

char IsPressed_A(int PinNum);
char IsPressed_B(int PinNum);
char IsPressed_C(int PinNum);
char IsPressed_D(int PinNum);

void SetPin_A(int PinNUM);
void SetPin_B(int PinNUM);
void SetPin_C(int PinNUM);
void SetPin_D(int PinNUM);


void ReSetPin_A(int PinNUM);
void ReSetPin_B(int PinNUM);
void ReSetPin_C(int PinNUM);
void ReSetPin_D(int PinNUM);

void Toggle_A(int PinNUM);
void Toggle_B(int PinNUM);
void Toggle_C(int PinNUM);
void Toggle_D(int PinNUM);


void Dir_A(char state,int PinNum);
void Dir_B(char state,int PinNum);
void Dir_C(char state,int PinNum);
void Dir_D(char state,int PinNum);





#endif /* GPIO_H_ */