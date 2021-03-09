/*
 * ExtInterrupt.h
 *
 * Created: 1/16/2021 9:07:59 PM
 *  Author: Arafa
 */ 


#ifndef EXTINTERRUPT_H_
#define EXTINTERRUPT_H_

#define LowLevel    0
#define AnyLogic    1
#define RisingEdge  2
#define FallingEdge 3

void ExtINT0_Init(int INTsenseControl);
void ExtINT1_Init(int INTsenseControl);
void ExtINT2_Init(int INTsenseControl);

void  ExtINT_disable(int INTnumber);



#endif /* EXTINTERRUPT_H_ */