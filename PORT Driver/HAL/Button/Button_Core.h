/*
 * Button_Core.h
 *
 * Created: 9/15/2023 10:04:56 AM
 *  Author: amgad
 */ 


#ifndef BUTTON_CORE_H_
#define BUTTON_CORE_H_

#include "BIT_MATH.h"
#include "MCU.h"

#define F_CPU 16000000U
#include <util/delay.h>

void Button_Init(void);
uint8 Button_GetValue(void);

#endif /* BUTTON_CORE_H_ */