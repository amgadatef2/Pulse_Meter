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


int main(void)
