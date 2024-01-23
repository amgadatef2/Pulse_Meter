/*
 * SevenSegment_Core.c
 *
 * Created: 9/15/2023 12:55:59 PM
 *  Author: amgad
 */ 

#include "SevenSegment_Core.h"
uint8 SevenSegment_Values[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XDE};
void SevenSegment_Init(void)
{
	DDRA=0XFF; //All output
	SET_BIT(DDRC,6); //7 segment Right Enable pin Output
	SET_BIT(DDRC,7); //7 segment Left Enable pin Output
}
void SevenSegment_Write(uint8 num)
{
	SET_BIT(PORTC,6);  //Right 7 segment Enable
	CLR_BIT(PORTC,7);  //Left 7 segment Disable
	PORTA=SevenSegment_Values[num%10]; // a7ad
	_delay_ms(1);
	SET_BIT(PORTC,7);   //Left 7 segment Enable
	CLR_BIT(PORTC,6);  //Right 7 segment Disable
	PORTA=SevenSegment_Values[num/10]; // 3shrat
	_delay_ms(1);
}