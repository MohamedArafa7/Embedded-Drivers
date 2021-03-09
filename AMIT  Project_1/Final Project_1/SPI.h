/*
 * SPI.h
 *
 * Created: 2/13/2021 7:15:32 PM
 *  Author: Arafa
 */ 


#ifndef SPI_H_
#define SPI_H_

#define Slave  0
#define Master 1

#define SCK  7
#define MISO 6
#define MOSI 5
#define SS   4

#define SPI_CLK_Div4   0
#define SPI_CLK_Div16  1
#define SPI_CLK_Div64  2
#define SPI_CLK_Div128 3
#define SPI_CLK_Div2   4
#define SPI_CLK_Div8   5
#define SPI_CLK_Div32  6

#define SPI_StoreH 0
#define SPI_StoreL 1


void SPI_Init(int Type, int clk);
void SPI_Store(int Store);
void SPI_Enable(void);
void SPI_Disable(void);
char SPI_Read(void);
void SPI_Data(char data);
void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);
void SPI_ChangeMode(int mode);


#endif /* SPI_H_ */