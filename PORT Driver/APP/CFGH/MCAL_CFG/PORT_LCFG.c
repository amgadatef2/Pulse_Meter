/*
 * PORT_LCFG.c
 *
 * Created: 9/16/2023 12:15:32 PM
 *  Author: alima
 */ 

#include "PORT_LCFG.h"

PIN_PARAMETERS PORT_Initialization[DEFINED_PINS]=
{
	/*LCD Pins*/ 
	{ PORTA_PIN1   ,  PIN_DIR_OUTPUT  },
	{ PORTA_PIN2   ,  PIN_DIR_OUTPUT  },
	{ PORTA_PIN3   ,  PIN_DIR_OUTPUT  },
	{ PORTA_PIN4   ,  PIN_DIR_OUTPUT  },
	{ PORTA_PIN5   ,  PIN_DIR_OUTPUT  },
	{ PORTA_PIN6   ,  PIN_DIR_OUTPUT  },
	/*KeyPad Pins*/ 
	{ PORTB_PIN3  ,  PIN_DIR_OUTPUT   }, /* for pwm 3,4,5  motor*/
	{ PORTB_PIN4  ,  PIN_DIR_OUTPUT   },
	{ PORTB_PIN5  ,  PIN_DIR_OUTPUT   },
	{ PORTB_PIN6   ,  PIN_DIR_OUTPUT   },
	{ PORTD_PIN2   ,  PIN_DIR_INPUT   },
	{ PORTD_PIN3   ,  PIN_DIR_INPUT   },
	{ PORTD_PIN4   ,  PIN_DIR_OUTPUT   },
	{ PORTD_PIN5   ,  PIN_DIR_INPUT   },
		{ PORTD_PIN6  ,  PIN_DIR_INPUT   },
	
	
	{ PORTD_PIN2   ,  PIN_DIR_INPUT },
    { PORTC_PIN2   ,  PIN_DIR_OUTPUT },
		{ PORTA_PIN0   ,  PIN_DIR_INPUT },
		
				
						
};  //This is Array of Structs