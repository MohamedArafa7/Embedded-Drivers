

#define in_Pin  0
#define out_Pin 1

#define ON  1
#define OFF 0
#define LOW 0
#define HIGH 1

void GPIO_Init(char PORT);

void Dir_PinA(int PinNum, char state);
void Dir_PinB(int PinNum, char state);
void Dir_PinC(int PinNum, char state);
void Dir_PinD(int PinNum, char state);
void Dir_PinE(int PinNum, char state);
void Dir_PinE(int PinNum, char state);
void Dir_PinF(int PinNum, char state);


void Set_PinA(int PinNum);
void Set_PinB(int PinNum);
void Set_PinC(int PinNum);
void Set_PinD(int PinNum);
void Set_PinE(int PinNum);
void Set_PinF(int PinNum);

void Reset_PinA(int PinNum);
void Reset_PinB(int PinNum);
void Reset_PinC(int PinNum);
void Reset_PinD(int PinNum);
void Reset_PinE(int PinNum);
void Reset_PinF(int PinNum);

void Toggle_PinA(int PinNum);
void Toggle_PinB(int PinNum);
void Toggle_PinC(int PinNum);
void Toggle_PinD(int PinNum);
void Toggle_PinE(int PinNum);
void Toggle_PinF(int PinNum);


int Read_PinA(int PinNum,char state);
int Read_PinB(int PinNum,char state);
int Read_PinC(int PinNum,char state);
int Read_PinD(int PinNum,char state);
int Read_PinE(int PinNum,char state);
int Read_PinF(int PinNum,char state);


void Dir_LPORTA(char state);
void Dir_LPORTB(char state);
void Dir_LPORTC(char state);
void Dir_LPORTD(char state);
void Dir_LPORTE(char state);
void Dir_LPORTF(char state);

void Dir_HPORTA(char state);
void Dir_HPORTB(char state);
void Dir_HPORTC(char state);
void Dir_HPORTD(char state);
