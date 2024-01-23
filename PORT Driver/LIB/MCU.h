/*
 * MCU.h
 *
 * Created: 9/15/2023 10:06:24 AM
 *  Author: amgad
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD.h"


/****************** GPIO Registers **************/
#define PINA   *(volatile uint8*)(0x39)
#define DDRA   *(volatile uint8*)(0x3A)
#define PORTA  *(volatile uint8*)(0x3B)

#define PINB   *(volatile uint8*)(0x36)
#define DDRB   *(volatile uint8*)(0x37)
#define PORTB  *(volatile uint8*)(0x38)

#define PINC   *(volatile uint8*)(0x33)
#define DDRC   *(volatile uint8*)(0x34)
#define PORTC  *(volatile uint8*)(0x35)

#define PIND   *(volatile uint8*)(0x30)
#define DDRD   *(volatile uint8*)(0x31)
#define PORTD  *(volatile uint8*)(0x32)
/************************************************/

/************************************** EXTERNAL INT Registers ******************************/
#define SREG   (*(volatile uint8*)(0X5F))
#define GICR   (*(volatile uint8*)(0X5B))
#define MCUCR  (*(volatile uint8*)(0X55))
#define MCUCSR (*(volatile uint8*)(0X54))


/*************************************** ADC Registers ************************************************/#define ADMUX                      (*(volatile uint8 *)(0x27))#define ADCSRA                     (*(volatile uint8 *)(0x26))#define ADCH                       (*(volatile uint8 *)(0x25))#define ADCL                       (*(volatile uint8 *)(0x24))#define ADC_INPUT_16BIT_ACCESS     (*(volatile uint16*)(0x24))#define SFIOR                      (*(volatile uint8 *)(0x50))/*******************************************************************************************************/


/************************************************timers*******************************************************/
#define TCNT0               (*(volatile uint8*)(0x52))
#define TCCR0               (*(volatile uint8*)(0x53))
#define OCR0                (*(volatile uint8*)(0x5C))
#define TIMSK               (*(volatile uint8*)(0x59))
#define TCCR1A              (*(volatile uint8*)(0x4F))
#define TCCR1B              (*(volatile uint8*)(0x4E))
#define TCNT1H              (*(volatile uint8*)(0x4D))
#define TCNT1L              (*(volatile uint8*)(0x4C))
#define TCNT1_16BIT_ACCESS  (*(volatile uint16*)(0x4C))
#define OCR1AH              (*(volatile uint8*)(0x4B))
#define OCR1AL              (*(volatile uint8*)(0x4A))
#define OCR1A_16BIT_ACCESS  (*(volatile uint16*)(0x4A))
#define OCR1BH              (*(volatile uint8*)(0x49))
#define OCR1BL              (*(volatile uint8*)(0x48))
#define OCR1B_16BIT_ACCESS  (*(volatile uint16*)(0x48))
#define ICR1H               (*(volatile uint8*)(0x47))
#define ICR1L               (*(volatile uint8*)(0x46))
#define ICR1_16BIT_ACCESS   (*(volatile uint16*)(0x46))



#endif /* MCU_H_ */