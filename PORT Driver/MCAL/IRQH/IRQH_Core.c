
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IRQH_core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IRQH_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*ptr) (void) = NULL;
void (*GPT_ptr) (void) = NULL;


extern uint32 ADC_Vin_Value_mv;
 extern uint32  TIMER_NUMBER_OVERFLOWS_G ;
 uint32  TIMER1_NUMBER_OVERFLOWS_G ;
 extern uint32   TIMER0_INIT_VALUE_G ;
 
 
 /*ICU VARIABLES*/
 extern volatile uint32 capture_reading_1_g ;
 extern volatile uint32 capture_reading_2_g ;
  extern volatile uint32 capture_reading_3_g ;
 extern volatile uint32 capture_flag_g ;


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void IRQH_SetGlobalInterrupts (uint8 G_INT_State)
{
	switch (G_INT_State)
	{
		case INTERRUPT_ENABLE :
		SET_BIT(SREG , 7);
		break;
		case INTERRUPT_DISABLE :
		CLR_BIT(SREG , 7);
		break;
		default:
		break;
	}
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void IRQH_SetExternalInterrupts (void)
{
	#if   (EXT_INT0_STATE == INTERRUPT_ENABLE)
	SET_BIT (GICR , 6);
	   #if   (EXT_INT0_TRIGGER == RISING_EDGE_TRIGGER)
	     SET_BIT (MCUCR , 0);
	     SET_BIT (MCUCR , 1);
	   #elif (EXT_INT0_TRIGGER == FALLING_EDGE_TRIGGER)
	     CLR_BIT (MCUCR , 0);
	     SET_BIT (MCUCR , 1);
	   #elif (EXT_INT0_TRIGGER == LOW_LEVEL_TRIGGER)
	     CLR_BIT (MCUCR , 0);
	     CLR_BIT (MCUCR , 1);
	   #elif (EXT_INT0_TRIGGER == ANY_LOGICAL_CHANGE_TRIGGER)
	     SET_BIT (MCUCR , 0);
	     CLR_BIT (MCUCR , 1);
	   #endif //#if   (EXT_INT0_TRIGGER == RISING_EDGE_TRIGGER)
	
	#elif (EXT_INT1_STATE == INTERRUPT_ENABLE)
	SET_BIT (GICR , 7);
	   #if   (EXT_INT1_TRIGGER == RISING_EDGE_TRIGGER)
	   SET_BIT (MCUCR, 2);
	   SET_BIT (MCUCR, 3);
	   #elif (EXT_INT1_TRIGGER == FALLING_EDGE_TRIGGER)
	   CLR_BIT (MCUCR, 2);
	   SET_BIT (MCUCR, 3);
	   #elif (EXT_INT1_TRIGGER == LOW_LEVEL_TRIGGER)
	   CLR_BIT (MCUCR, 2);
	   CLR_BIT (MCUCR, 3);
	   #elif (EXT_INT1_TRIGGER == ANY_LOGICAL_CHANGE_TRIGGER)
	   SET_BIT (MCUCR ,2);
	   CLR_BIT (MCUCR ,3);
	   #endif //#if   (EXT_INT1_TRIGGER == RISING_EDGE_TRIGGER)
	   
	#elif (EXT_INT2_STATE == INTERRUPT_ENABLE)
	SET_BIT (GICR , 5);
	   #if   (EXT_INT2_TRIGGER == RISING_EDGE_TRIGGER)
	   SET_BIT (MCUCSR, 6);
	   #elif (EXT_INT2_TRIGGER == FALLING_EDGE_TRIGGER)
	   CLR_BIT (MCUCSR, 6);
	   #endif //#if   (EXT_INT2_TRIGGER == RISING_EDGE_TRIGGER)
	#endif // #if   (EXT_INT0_STATE == INTERRUPT_ENABLE) 
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void IRQH_SetCallBack (void(*p)(void))
{
	ptr = p;
}

ISR(INT0_vect)
{
	(*ptr)();
}

ISR(ADC_vect)
{
	ADC_Vin_Value_mv = (ADC_INPUT_16BIT_ACCESS * 5000) / 1024;
}

ISR(TIMER0_OVF_vect){
		  static uint8 ovf_interrupt_cnt=0;
		 ovf_interrupt_cnt++;
		 if(ovf_interrupt_cnt==TIMER_NUMBER_OVERFLOWS_G){
			 (*ptr)();
			 ovf_interrupt_cnt=0;
			 TCNT0=TIMER0_INIT_VALUE_G;
		 }
		  
		
	
}

ISR (TIMER1_COMPA_vect){
	(*ptr)();
}

ISR(TIMER1_OVF_vect){
	TIMER1_NUMBER_OVERFLOWS_G++;
	
	
}


ISR (TIMER1_CAPT_vect){
	capture_flag_g++;
	if(capture_flag_g==1){
		capture_reading_1_g=ICR1_16BIT_ACCESS;
		TIMER1_NUMBER_OVERFLOWS_G=0;
		/*DETECTION FAILING EDGE*/
		CLR_BIT(TCCR1B,6);
		
	}
	else if(capture_flag_g==2){
			capture_reading_2_g=ICR1_16BIT_ACCESS+(TIMER1_NUMBER_OVERFLOWS_G*65536);
			/*detect rising edge*/
			TCCR1B|=0x40;
			/*disable icu inturrpt*/
			
			
		}
		else if(capture_flag_g==3){
			capture_reading_3_g=ICR1_16BIT_ACCESS+(TIMER1_NUMBER_OVERFLOWS_G*65536);
			 CLR_BIT(TIMSK,5);
		}
}
/**********************************************************************************************************************
 *  END OF FILE: IRQH_core.c
 *********************************************************************************************************************/
