/*
 * PWM_core.c
 *
 * Created: 10/24/2023 8:47:20 PM
 *  Author: amgad
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PWM_core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void pwm_init(void){
	#if (PWM0_STATE== PWM_ENABLE)
	#if (PWM0_TYPE == PWM_FAST)
	SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
	
	#elif (PWM0_TYPE == PWM_PHASE_CORRECT)
		CLR_BIT(TCCR0,3);
			SET_BIT(TCCR0,3);
	
	#endif /*(PWM0_TYPE == PWM_FAST)*/
	#if (PWM0_MODE== PWM_NONINVERTED)
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
		#elif (PWM0_MODE== PWM_INVERTED)
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif /*(PWM0_MODE== PWM_NONINVERTED)*/
	
	#endif /*(PWM0_STATE== PWM_ENABLE)*/
	#if (PWM1_STATE== PWM_ENABLE)
	TCCR1A|=0X02;
	TCCR1B|=0X18;
	TCCR1A|=0X80;
	
	#endif  /* (PWM1_STATE== PWM_ENABLE)*/
	
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
void pwm0_genrate(uint8 duty_cycle){
	#if (PWM0_STATE== PWM_ENABLE)
	#if (PWM0_TYPE ==PWM_FAST)
	
	#if  (PWM0_MODE ==PWM_NONINVERTED)
	OCR0=((duty_cycle * 256) / 100) - 1;
	
	#elif  (PWM0_MODE ==PWM_INVERTED)
	OCR0= 255 -((duty_cycle * 256) / 100) ;
	#endif /* (PWM0_MODE ==PWM_NONINVERTED)*/
	
	#elif (PWM0_TYPE ==PWM_PHASE_CORRECT)
		#if  (PWM0_MODE ==PWM_NONINVERTED)
		OCR0=((duty_cycle * 255) / 100);
		
		#elif  (PWM0_MODE ==PWM_INVERTED)
		OCR0= 255 -((duty_cycle * 255) / 100) ;
		#endif /* (PWM0_MODE ==PWM_NONINVERTED)*/
		
	#endif /*(PWM0_TYPE ==PWM_FAST)*/
	
	#if (PWM0_PRESC == PWM_PRESC8)
	TCCR0|=0x02;
	#elif (PWM0_PRESC == PWM_PRESC64)
	TCCR0|=0x03;
	#elif (PWM0_PRESC == PWM_PRESC256)
	TCCR0|=0x04;
	#elif (PWM0_PRESC == PWM_PRESC1024)
TCCR0|=0x05;

#endif /* (PWM0_PRESC == PWM_PRESC8)*/
	
	#endif  /*(PWM0_STATE== PWM_ENABLE)*/
	
}


void pwm1_genrate(uint8 FREQUANCY ,uint8 duty_cycle){
	ICR1_16BIT_ACCESS=(16000000/(PWM1_PRESC*FREQUANCY));
	OCR1A_16BIT_ACCESS=((duty_cycle*(ICR1_16BIT_ACCESS+1))/100)-1;
	TCCR1B|=0X05;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
