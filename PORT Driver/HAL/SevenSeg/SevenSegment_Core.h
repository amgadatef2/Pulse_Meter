/*
 * SevenSegment_Core.h
 *
 * Created: 9/15/2023 12:56:22 PM
 *  Author: amgad
 */ 


#ifndef SEVENSEGMENT_CORE_H_
#define SEVENSEGMENT_CORE_H_

#define F_CPU 16000000U
#include <util/delay.h>

#include "BIT_MATH.h"
#include "MCU.h"

void SevenSegment_Init(void);
void SevenSegment_Write(uint8);



#endif /* SEVENSEGMENT_CORE_H_ */