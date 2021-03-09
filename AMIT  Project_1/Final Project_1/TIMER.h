/*
 * TIMER.h
 *
 * Created: 2/6/2021 7:03:28 PM
 *  Author: Arafa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define T0_NormalMode  0
#define T0_PWMMode     1
#define T0_CTCMode     1
#define T0_FPWMMode    1

#define T1_Normal_INT  2
#define T1_CMP_B_INT   3
#define T1_CMP_A_INT   4
#define T1_Cap_INT     5  

#define T2_NormalMode  6
#define T2_PWMMode     7
#define T2_CTCMode     7
#define T2_FPWMMode    7

#define T1_NormalMode			0
#define T1_PWM_phase_8			1
#define T1_PWM_phase_9			2
#define T1_PWM_phase_10			3
#define T1_CTC_Cmp				4
#define T1_FPWM_8				5
#define T1_FPWM_9				6
#define T1_FPWM_10				7
#define T1_PWM_phase_Freq_Cap	8
#define T1_PWM_phase_Freq_Cmp	9
#define T1_PWM_phase_Cap		10
#define T1_PWM_phase_Cmp		11
#define T1_CTC_Cap				12
#define T1_FPWM_Cap				14
#define T1_FPWM_Cmp				15



#define T0_T1_CLK_NoDiv   1
#define T0_T1_ClkDiv_8    2
#define T0_T1_ClkDiv_64   3
#define T0_T1_ClkDiv_256  4
#define T0_T1_ClkDiv_1024 5
#define T0_T1_CLK_EXT_F   6
#define T0_T1_CLK_EXT_R   7

#define T2_CLK_NoDiv    1
#define T2_ClkDiv_8     2
#define T2_ClkDiv_32    3
#define T2_ClkDiv_64    4
#define T2_ClkDiv_128   5
#define T2_ClkDiv_256   6
#define T2_ClkDiv_1024  7


#define CTC_DoNothing  0
#define CTC_toggle     1
#define CTC_Reset      2
#define CTC_Set		   3




#define FPWM_DoNothing	0 // port configurations
#define FPWM_NonInvert  2 // clear in match,set on bottom
#define FPWM_Invert     3 // set in match,clear on bottom

#define PWM_DoNothing        0 // port configurations
#define PWM_ClearUpSetDown   2 // clear in match count up,set in match count down
#define PWM_SetUpClearDown   3 // Set in match count up,Clear in match count down

#define Servo_0degree 250
#define Servo_180degree 236 
 
void TIMER0_Disable(void);

void TIMER0_Enable(int freq);

void TIMER0_InitNormal(void);

void TIMER0_InitCTC(char CmpValue,int CmpAction);

void TIMER0_InitPWM(int PWMAction);

void TIMER0_InitFPWM(int FPWMAction);

void TIMER0_PWMWidth(char PWMValue);

void TIMER0_FPWMWidth(char FPWMValue);

void TIMER0_IinterruptDisable(int mode);

void TIMER0_IinterruptEnable(int mode);

void TIMER0_poolFlag(int mode);


void TIMER1_Disable(void);

void TIMER1_Enable(int freq);

void TIMER1_InitNormal(void);

void TIMER1_InitCTC(int CmpValue,int CmpAction);

void TIMER1_InitPWM(int PWMAction);

void TIMER1_InitFPWM_Fixed(short BitsNum,short DutyCycle ,int FPWMAction);

void TIMER1_InitFPWM_Cmp(short MaxValue,short dutycycle ,int FPWMAction);

void TIMER1_InitFPWM(int mode ,int FPWMAction);

void TIMER1_PWMWidth(short PWMValue);

void TIMER1_FPWMWidth(char FPWMValue);

void TIMER1_IinterruptDisable(int mode);

void TIMER1_IinterruptEnable(int mode);


void TIMER2_Disable(void);

void TIMER2_Enable(int freq);

void TIMER2_InitNormal(void);

void TIMER2_InitCTC(char CmpValue,int CmpAction);

void TIMER2_InitPWM(int PWMAction);

void TIMER2_InitFPWM(int FPWMAction);

void TIMER2_PWMWidth(char PWMValue);

void TIMER2_FPWMWidth(char FPWMValue);

void TIMER2_IinterruptDisable(int mode);

void TIMER2_IinterruptEnable(int mode);

void TIMER2_poolFlag(int mode);

void ServoT2_Init(void);

void ServoT2_Degree(int degree);

#endif /* TIMER_H_ */