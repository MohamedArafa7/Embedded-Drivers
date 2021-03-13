#include"tm4c123gh6pm.h"
#include"LCD4.h"
#include"GPIO.h"
#include"MyBoard.h"


void LCD4_Init(void)
{
	Dir_LPORTD(out_Pin);
	Dir_LPORTE(out_Pin);
	Reset_PinE(RWLCD4F);
	
	LCD4_Command(0x02); // 4_bit LCD
	LCD4_Command(0x0C);  // Cursor off, display on
	delay_ms(10);
	LCD4_Clear();
	
}	
void LCD4_Command(char cmd)
{
	LCD_Data4 = ((LCD_Data4) & 0xF0)|((cmd & 0xF0)>>4);
	Reset_PinE(1);
	LCD4_Enable();
		delay_ms(1);
	LCD_Data4 = (LCD_Data4 & 0xF0)| ((cmd & 0x0F));
	Reset_PinE(1);
	LCD4_Enable();

}
void LCD4_Data(char data)
{
		LCD_Data4 = ((LCD_Data4) & 0xF0)|((data & 0xF0)>>4);
		Set_PinE(RsLCD4);
		LCD4_Enable();
		delay_ms(1);
	LCD_Data4 = (LCD_Data4 & 0xF0)| ((data & 0x0F));
	Set_PinE(RsLCD4);
	LCD4_Enable();
}
void LCD4_Clear(void)
{
	LCD4_Command(LCDclear);
	delay_ms(1);
}
void LCD4_Enable(void)
{
		Set_PinE(EnLCD4);
	delay_ms(10);
	Reset_PinE(EnLCD4);
	delay_ms(5);
	
}
void LCD4_IntData(int data)
{
	int length = 1;
	int i;
	int d ;
	char str[11];
	if (data < 0)
	{
		LCD4_Data('-');
		data = data*(-1);
	}
  d = data;
	while( d > 0 )
	{
		length++;
		d /= 10;
		
	}
	for (i = length-2; i >= 0; i--)
	{
		str[i] = '0' + (data % 10);
		data /= 10;
	}
	str[length-1] = '\0';
	LCD4_StrData(str);
}

	void LCD4_StrData(char* s)
{
	int i;
	for ( i= 0; s[i] !='\0';i++)
	{
		LCD4_Data(s[i]);
	}
}
