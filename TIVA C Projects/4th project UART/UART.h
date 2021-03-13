#define UART_5Bits 0
#define UART_6Bits 1
#define UART_7Bits 2
#define UART_8Bits 3

#define UART_RX_INT 4
#define UART_TX_INT 5

#define SYSCLK 16000000 

void UART0_Init(int BaudRate,int BitNum);
void UART0_InterruptEnable(int periority);
void UART0_InterruptDisable(void);
void UART0_Enable(void);
void UART0_Disable(void);
void UART0_Data(char data);
void UART0_Str(char * data);
char UART0_ReadData(void);
int UART0_DataAvelable(void);

void UART1_Init(int BaudRate,int BitNum);
void UART1_InterruptEnable(int periority);
void UART1_InterruptDisable(void);
void UART1_Enable(void);
void UART1_Disable(void);
void UART1_Data(char data);
void UART1_Str(char * data);
char UART1_ReadData(void);
int UART1_DataAvelable(void);
