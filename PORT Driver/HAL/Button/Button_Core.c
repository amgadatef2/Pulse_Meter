/*
 * Button_Core.c
 *
 * Created: 9/15/2023 10:04:44 AM
 *  Author: amgad
 */ 

#include "Button_Core.h"

void Button_Init(void)
{
	CLR_BIT(DDRD,2); //Input
}
uint8 Button_GetValue(void)
{
	uint8 Temp=0;
	uint8 Button=1;
	Button=GET_BIT(PIND,2);
	
	while(Temp==0)
	{
		Temp= GET_BIT(PIND,2);
	}
	_delay_ms(10);
	return Button;
}