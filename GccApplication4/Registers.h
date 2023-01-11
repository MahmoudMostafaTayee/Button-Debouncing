/*
 * Register.h
 *
 * Author: Mahmoud Mostafa Tayee
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
typedef unsigned char uint8_t;

/****************************************************************************************/
/* This registers implementation is for ATmega324P                                      */
/* http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42743-ATmega324P_Datasheet.pdf */
/****************************************************************************************/

/************************************************************************/
/* DIO REGISTERS                                                        */
/************************************************************************/
// PORTA register
#define PORTA *((volatile uint8_t*) 0X3B)
#define DDRA *((volatile uint8_t*) 0X3A)
#define PINA *((volatile uint8_t*) 0X39)

// PORTB register
#define PORTB *((volatile uint8_t*) 0x25)
#define DDRB *((volatile uint8_t*) 0x24)
#define PINB *((volatile uint8_t*) 0x23)

// PORTC register
#define PORTC *((volatile uint8_t*) 0X35)
#define DDRC *((volatile uint8_t*) 0X34)
#define PINC *((volatile uint8_t*) 0X33)

// PORTD register
#define PORTD *((volatile uint8_t*) 0X32)
#define DDRD *((volatile uint8_t*) 0X31)
#define PIND *((volatile uint8_t*) 0X30)

#endif /* REGISTERS_H_ */