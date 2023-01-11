/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 



#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO/dio.h"
// Defining button #1
#define BUTTON_1_PORT PORT_B
#define BUTTON_1_PIN PIN1


//initialize for the pin on a specific port to be connected to a button (to be input)
void buttonInit(uint8_t buttonPort, uint8_t buttonPin);

//Read the value on the button connected to a specific pin.
void buttonRead(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);


#endif /* BUTTON_H_ */