/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 

#ifndef LED_H_
#define LED_H_

//Include the DIO driver to communicate with the Microcontroller DIO with a level of abstraction.
#include "../../MCAL/DIO/dio.h"

// Specifies the CPU frequency to be considered by the delay macros.
#define F_CPU 1000000U //1Mhz

// Include the delay library.
#include <util/delay.h> // to use delay function

//Define on what are the ports that my leds are connected to.
#define LED_1_PORT PORT_B // Port of the first led
#define LED_1_PIN PIN0 //  Pin of the  first pin on PORTB

#define LED_2_PORT PORT_B // Port of the first led
#define LED_2_PIN PIN2 //  Pin of the  first pin on PORTB


void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */