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
#include "GPT_core.h"
#include "MCU.h"
#include "STD.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32  TIMER_NUMBER_OVERFLOWS_G =0;
uint32   TIMER0_INIT_VALUE_G =0;
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
void GPT_INIT(void){
	#if  (TIMER0_STATE == TIMER_ENABLE) 
	
	#if   (TIMER0_MODE == NORMAL_MODE)
	CLR_BIT(TCCR0 ,3);
	CLR_BIT(TCCR0 ,6);
	 
	 #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLE)
	 SET_BIT(TIMSK,0);
	 #elif (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLE)
	 CLR_BIT(TIMSK,0);
	 
	 #endif  /* #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	
	#elif   (TIMER0_MODE == CTC_MODE)
	
	#endif  /*(TIMER0_MODE == NORMAL_MODE)*/
	#if (TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )
	TCCR0 |= 0X01;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_8		 )
	TCCR0 |= 0X02;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_64		 )
	TCCR0 |= 0X03;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_256		 )
	TCCR0 |= 0X04;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_1024		 )
	TCCR0 |= 0X05;
	#endif /*if(TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )*/
	
	
#endif  /*  #if  (TIMER0_STATE == TIMER_ENABLE) */

#if  (TIMER1_STATE == TIMER_ENABLE)
	#if   (TIMER1_MODE == NORMAL_MODE)
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,3);
	CLR_BIT(TCCR1A,4);
	 
	 #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLE)
	 SET_BIT(TIMSK,2);

	 #elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLE)
	 CLR_BIT(TIMSK,2);
	
	 #endif  /* #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	 
	
	#elif  (TIMER1_MODE == CTC_MODE)
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,3);
	CLR_BIT(TCCR1A,4);
	 
	 #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLE)
	SET_BIT(TIMSK,4);
	 #elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLE)
	CLR_BIT(TIMSK,4);
	 
	 #endif  /* #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	 
	
	
	#endif /*(TIMER1_MODE == NORMAL_MODE)*/
	#if (TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )
	TCCR1B|=0x01;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_8		 )
    TCCR1B|=0x02;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_64		 )
	TCCR1B|=0x03;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_256		 )
	TCCR1B|=0x04;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_1024		 )
	TCCR1B|=0x05;
	#endif /*if(TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )*/


#endif  /*  #if  (TIMER1_STATE == TIMER_ENABLE) */


#if  (TIMER2_STATE == TIMER_ENABLE)

#endif  /*  #if  (TIMER2_STATE == TIMER_ENABLE) */





	
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
void GPT_SetTime(void){
	
	uint8  MCU_CLK_ms =16;
	
	#if (TIMER0_STATE== TIMER_ENABLE)
	#if (TIMER0_MODE == NORMAL_MODE)
	uint8 TIMER0TICK_TIME_us =TIMER0_PRESCALER / MCU_CLK_ms;
	uint32 time_ms=TIMER0_COUNTED_MS;
    uint32 timer0total_ticks=(time_ms *1000) /TIMER0TICK_TIME_us;
	TIMER_NUMBER_OVERFLOWS_G= timer0total_ticks/256;
	TIMER0_INIT_VALUE_G=256 -(timer0total_ticks%256);
	TCNT0=TIMER0_INIT_VALUE_G;
	if (timer0total_ticks%256!=0 ){
		TIMER_NUMBER_OVERFLOWS_G++;
		}
	
	#endif  /*(TIMER0_MODE == NORMAL_MODE)*/
	
	#endif /* #if (TIMER0_STATE== TIMER_ENABLE)*/
	
	#if (TIMER1_STATE ==TIMER_ENABLE)
	#if (TIMER1_MODE ==CTC_MODE)
	uint8 TIMER1TICK_TIME_us =TIMER1_PRESCALER / MCU_CLK_ms;
	uint32 time1_ms=TIMER1_COUNTED_MS;
	uint32 timer1total_ticks=(time1_ms *1000) /TIMER1TICK_TIME_us;
	OCR1A_16BIT_ACCESS= timer1total_ticks -  1;
	
	
	
	
	
	
	#endif /*(TIMER1_MODE ==CTC_MODE)*/
	#endif  /*(TIMER1_STATE ==TIMER_ENABLE)*/
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
