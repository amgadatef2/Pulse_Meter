/*
 * Button with LEDs.c
 *
 * Created: 9/12/2023 9:45:35 PM
 * Author : amgad atef
 */ 


#include "PORT_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "LED_Core.h"
#include <avr/interrupt.h> // we will understand but not today
#include "IRQH_Core.h"
#include "SevenSegment_Core.h"
#include "ADC_Core.h"
#include "GPT_core.h"
#include "PWM_core.h"
#include "DC_MOTOR_CORE.h"
#include "ultrasonic_core.h"
#include "pulse_meter_core.h"
#include "ICU_CORE.h"

extern uint32 ADC_Vin_Value_mv;
extern volatile uint32 capture_flag_g;
extern volatile uint32 capture_reading_1_g;
extern volatile uint32 capture_reading_2_g;
extern volatile uint32 capture_reading_3_g;


int main(void){	uint32 Duty_Cycle = 0;	uint32 Frequency = 0;		PORT_Init();	LCD_Init();		GPT_INIT();		pwm_init();	pwm0_genrate(80);		IRQH_SetGlobalInterrupts(INTERRUPT_ENABLE);	ICU_INIT();				while (1)	{		if (capture_flag_g == 3)		{			Duty_Cycle = ((capture_reading_2_g - capture_reading_1_g)* 100) / (capture_reading_3_g - capture_reading_1_g);			Frequency = 16000000 / ((capture_reading_3_g - capture_reading_1_g) * 1024);						LCD_GoTo(0 , 0);			LCD_WriteString("Duty_Cycle = ");			LCD_WriteInteger(Duty_Cycle);			LCD_WriteChar('%');						LCD_GoTo(1 , 0);			LCD_WriteString("Frequency = ");			LCD_WriteInteger(Frequency);			LCD_WriteString("Hz");						//Enable ICU INTERRUPT			SET_BIT(TIMSK , 5);			capture_flag_g =0;		}	}	}

