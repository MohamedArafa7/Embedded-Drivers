#include "tm4c123gh6pm.h"
#include "UART.h"



void UART0_Init(int BaudRate,int BitNum)
{
	volatile unsigned int delay;
	SYSCTL_RCGCUART_R |= (1 << 0); // Enable Clock for UART0
	SYSCTL_RCGC2_R |= (1<<0);    // Enable GPIO PortA For UART0
	
	// Some delays to get clock initted
	delay = SYSCTL_RCGCUART_R;
	delay = SYSCTL_RCGCGPIO_R;
	
	GPIO_PORTA_AFSEL_R |= (1 << 0) | (1 << 1); // Enable Alternative Fn for PA0,PA1
	GPIO_PORTA_PCTL_R &= ~((0xF << 0)|(0xF << 4));  //Clear Select Fn from PCTL PortA PA0,PA1
	GPIO_PORTA_PCTL_R |=(1 << 0)|(1 << 1);  // Select UART0 Fn For PA0,PA1
	GPIO_PORTA_AMSEL_R &= ~((1 << 0)|(1 << 1)); // Clear Analog Fn For PA0,PA1
	GPIO_PORTA_DR8R_R |= (1 << 0)|(1 << 1); // Drive current up to 8mA
	GPIO_PORTA_DEN_R |= (1 << 0)| (1<<1); // Enable digital Fn for PA1,PA2
	
	UART0_CTL_R &= ~(1 << 0); // Disable UART0 until configuration
	UART0_IBRD_R = (SYSCLK / (16 * BaudRate));  //Set int part of baud rate
	UART0_FBRD_R = (int)((((SYSCLK / (16.0 * (float )BaudRate))- (float)UART0_IBRD_R) * 64.0) + 0.5) ;  // Set float part of baud rate
	UART0_LCRH_R &= ~(0x3 << 5);    //Clear 2 bits of WLEN uset to select no. data bits
	UART0_LCRH_R |= (BitNum << 5); // Set data bits number
	UART0_CC_R = 0; // Select system clock sourc 
	
	//UART0_LCRH_R |= (1 << 4); // Enable FIFO buffers 16*8
	//UART0_LCRH_R |= (1 << 3); // For 2 stop bits
	
	UART0_CTL_R |= (1 << 9)| (1 << 8); //Enable TX and RX section
	//UART0_CTL_R |= (1 << 7); // Enable LOOP BACK option
	
	UART0_CTL_R &= ~(1 << 5); // For low Speed option UART CLK = SYSCLK / 16
	//UART0_CTL_R |= (1 << 5); // For high speed option UART CLK = SYSCLK / 8
	//UART0_CTL_R |= (1 << 4);  // Enable setting flag after transmitiom
	
}


void UART0_Enable(void)
{
	UART0_CTL_R |= (1 << 0); // Enable UART
}

void UART0_Disable(void)
{
	UART0_CTL_R &= ~(1 << 0); // Disable UART
}

void UART0_InterruptEnable(int periority)
{
	UART0_IM_R |= (1 << 4);   //// Enable interrupt RXIME  	
	NVIC_PRI1_R &= ~(0xF << 12); // clear periory for UART0
	NVIC_PRI1_R |= ((periority & 0x7) << 13); // Set periorty for UART0
	NVIC_EN0_R = (1 << 5); //Enable UART0 INT ENVIC
}
void UART0_InterruptDisable(void)
{
	UART0_IM_R &= ~(1 << 4);  // Disable interrupt not nedded
}

void UART0_Data(char data)
{
	while(!(UART0_FR_R & (1 << 7))); // loop until TX FIFO is empty
	UART0_DR_R = data;
}

void UART0_Str(char * data)
{
	int i = 0;
	for (; data[i] != '\0';i++) // get all chars of the string
		{
			UART0_Data(data[i]);//Send char by char ti send function
		}
}

char UART0_ReadData(void)
{
	return (char) UART0_DR_R;
}

int UART0_DataAvelable(void)
{
	return (UART0_FR_R & (1 << 6)); // check if their is data received and RX FIFO is full
}



void UART1_Init(int BaudRate,int BitNum)
{
	volatile unsigned int delay;
	SYSCTL_RCGCUART_R |= (1 << 1); // Enable Clock for UART1
	SYSCTL_RCGC2_R |= (1 << 1);    // Enable GPIO PortB For UART1
	
	// Some delays to get clock initted
	delay = SYSCTL_RCGCUART_R;
	delay = SYSCTL_RCGCGPIO_R;
	
	GPIO_PORTB_AFSEL_R |= (1 << 0) | (1 << 1);      // Enable Alternative Fn for PB0,PB1
	GPIO_PORTB_PCTL_R &= ~((0xF << 0)|(0xF << 4));  //Clear Select Fn from PCTL PortA PB0,PB1
	GPIO_PORTB_PCTL_R |=(1 << 0)|(1 << 1);          // Select UART0 Fn For PB0,PB1
	GPIO_PORTB_AMSEL_R &= ~((1 << 0)|(1 << 1));     // Clear Analog Fn For PB0,PB1
	GPIO_PORTB_DEN_R |= (1 << 0)| (1<<1);           // Enable digital Fn for PB1,PB2
	
	
	UART1_CTL_R &= ~(1 << 0); // Disable UART1 until configuration
	UART1_IBRD_R = (SYSCLK / (16 * BaudRate));  //Set int part of baud rate
	UART1_FBRD_R = (int)((((SYSCLK / (16.0 * (float )BaudRate))- (float)UART1_IBRD_R) * 64.0) + 0.5) ;  // Set float part of baud rate
	UART1_LCRH_R &= ~(0x3 << 5);   //Clear 2 bits of WLEN uset to select no. data bits
	UART1_LCRH_R |= (BitNum << 5); // Set data bits number
	UART1_CC_R = 0;                // Select system clock sourc
	
	
	//UART1_LCRH_R |= (1 << 4); // Enable FIFO buffers 16*8
	//UART1_LCRH_R |= (1 << 3); // For 2 stop bits
	
	UART1_CTL_R |= (1 << 9)| (1 << 8); //Enable TX and RX section
//	UART1_CTL_R |= (1 << 7);           // Enable LOOP BACK option
	
	UART1_CTL_R &= ~(1 << 5);   // For low Speed option UART CLK = SYSCLK / 16
	//UART1_CTL_R |= (1 << 5);  // For high speed option UART CLK = SYSCLK / 8
	//UART1_CTL_R |= (1 << 4);  // Enable setting flag after transmitiom
	
}

void UART1_Enable(void)
{
	UART1_CTL_R |= (1 << 0); // Enable UART
}

void UART1_Disable(void)
{
	UART1_CTL_R &= ~(1 << 0); // Disable UART
}

void UART1_InterruptEnable(int periority)
{
	UART1_IM_R |= (1 << 4);      // Enable interrupt RXIME  	
	NVIC_PRI1_R &= ~(0xF << 20); // clear periory for UART1
	NVIC_PRI1_R |= ((periority & 0x7) << 21); // Set periorty for UART1
	NVIC_EN0_R = (1 << 6); //Enable UART1 INT ENVIC
}
void UART1_InterruptDisable(void)
{
	UART1_IM_R &= ~(1 << 4);  // Disable interrupt not nedded
}

void UART1_Data(char data)
{
	while((UART1_FR_R & (1 << 5))); // loop while TX FIFO is full
	UART1_DR_R = data;
}

void UART1_Str(char * data)
{
	int i = 0;
	for (; data[i] != '\0';i++) // get all chars of the string
		{
			UART1_Data(data[i]);//Send char by char ti send function
		}
}

char UART1_ReadData(void)
{
	return (char) UART1_DR_R;
}

int UART1_DataAvelable(void)
{
	return (UART1_FR_R & (1 << 6)); // check if their is data received and RX FIFO is full
}
