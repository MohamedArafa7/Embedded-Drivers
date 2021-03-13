
#define RisingEdge  0
#define FallingEdge 1
#define BothEdges   2
#define LowLevel    3
#define HighLevel   4


#define INT_A (INT_GPIOA-16)
#define INT_B (INT_GPIOB-16)
#define INT_C (INT_GPIOC-16)
#define INT_D (INT_GPIOD-16)
#define INT_E (INT_GPIOE-16)
#define INT_F (INT_GPIOF-16)

void ExtINT_InitA(int PinNum,int Type);
void ExtINT_InitB(int PinNum,int Type);
void ExtINT_InitC(int PinNum,int Type);
void ExtINT_InitD(int PinNum,int Type);
void ExtINT_InitE(int PinNum,int Type);
void ExtINT_InitF(int PinNum,int Type);

void ExtINT_Disable(int PORTNum);
void ExtINT_En(int PORTNum,int Priority);
