
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ADC_Core.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ADC_CORE_H_
#define ADC_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ADC_CFG.h"
#include "MCU.h"
#include "BIT_MATH.h"
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   ADC_VREF_VCC                      0U#define   ADC_VREF_AREF                     1U#define   ADC_VREF_INTERNAL                 2U#define   ADC_CHANNEL_0                     0U#define   ADC_CHANNEL_1                     1U#define   ADC_CHANNEL_2                     2U#define   ADC_CHANNEL_3                     3U#define   ADC_CHANNEL_4                     4U#define   ADC_CHANNEL_5                     5U#define   ADC_CHANNEL_6                     6U#define   ADC_CHANNEL_7                     7U

#define   ADC_PRESCALER_2                   0U#define   ADC_PRESCALER_4                   1U#define   ADC_PRESCALER_8                   2U#define   ADC_PRESCALER_16                  3U#define   ADC_PRESCALER_32                  4U#define   ADC_PRESCALER_64                  5U#define   ADC_PRESCALER_128                 6U

#define   ADC_CONVERSION_SINGLE_CONVERSION               0U#define   ADC_CONVERSION_FREE_RUNNING                    1U#define   ADC_CONVERSION_Analog_Comparator               2U#define   ADC_CONVERSION_External_Interrupt_Request_0    3U#define   ADC_CONVERSION_Timer_Counter0_Compare_Match    4U#define   ADC_CONVERSION_Timer_Counter0_Overflow         5U#define   ADC_CONVERSION_Timer_Counter_Compare_Match_B   6U#define   ADC_CONVERSION_Timer_Counter1_Overflow         7U#define   ADC_CONVERSION_Timer_Counter1_Capture_Event    8U#define   ADC_INTERRUPT_DISABLED            0U#define   ADC_INTERRUPT_ENABLED             1U#define   ADC_LEFT_ADJUCT                   0U#define   ADC_RIGHT_ADJUCT                  1U#define   ADC_RESOLUTION                    10U#define   ADC_Vref_Value                    5U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void ADC_Init (void);
void ADC_Read (void);
 
#endif /* ADC_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: ADC_CORE_H_
 *********************************************************************************************************************/
