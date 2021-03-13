/*
 * UART.h
 *
 * Created: 1/23/2021 7:38:10 PM
 *  Author: Arafa
 */ 


#ifndef UART_H_
#define UART_H_

void UART_Init(unsigned int BR);
void UART_BaudRate(unsigned int rate);
void UART_Data(char data);
void UART_Str(char * data);
void UART_num(int data);
void UART_NL(void);

char UART_RX(void);


#endif /* UART_H_ */