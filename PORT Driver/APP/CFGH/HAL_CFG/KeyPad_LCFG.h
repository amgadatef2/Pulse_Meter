/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  KEYPAD_CFG.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   Row_numbers  4U
#define   Col_numbers  4U

#define   KEYPAD_COL_0       PORTD_PIN2#define   KEYPAD_COL_1       PORTD_PIN3#define   KEYPAD_COL_2       PORTD_PIN4#define   KEYPAD_COL_3       PORTD_PIN5#define   KEYPAD_ROW_0       PORTB_PIN4#define   KEYPAD_ROW_1       PORTB_PIN5#define   KEYPAD_ROW_2       PORTB_PIN6#define   KEYPAD_ROW_3       PORTB_PIN7 

#define   KEYPAD_ROW_START   KEYPAD_ROW_0
#define   KEYPAD_ROW_END     KEYPAD_ROW_3

#define   KEYPAD_COL_START   KEYPAD_COL_0
#define   KEYPAD_COL_END     KEYPAD_COL_3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern const uint8 KeyPad_Values[Row_numbers][Col_numbers];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 

#endif /* KEYPAD_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: KEYPAD_CFG.h
 *********************************************************************************************************************/





