/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 


#include "led.h"

// LED_init skeletal.
/*
	Just call the DIO_init with the arguments to accomplish the desired initialization for the desired port.
*/
void LED_init(uint8_t ledPort, uint8_t ledPin){
	// This function just calls the DIO to initialize the port of the desired led as output.
	DIO_init(ledPort, ledPin, OUT);
}

// LED_on skeletal.
/*
	Just call the DIO_write with the arguments and value HIGH to write 1 on the pin for the desired port.
*/
void LED_on(uint8_t ledPort, uint8_t ledPin){
	// This function just calls the DIO to write 1 on the desired port of the led.
	DIO_write(ledPort, ledPin, HIGH);
}

// LED_off skeletal.
/*
	Just call the DIO_write with the arguments and value LOW to write 0 on the pin for the desired port.
*/
void LED_off(uint8_t ledPort, uint8_t ledPin){
		// This function just calls the DIO to write 0 on the desired port of the led.
		DIO_write(ledPort, ledPin, LOW);
}

// LED_toggle skeletal.
/*
	Just call the DIO_toggle with the arguments to invert the value on the pin.
*/
void LED_toggle(uint8_t ledPort, uint8_t ledPin){
		// This function just calls the DIO to change the state of the desired port of the led from 1 to 0 and vice versa.
		DIO_toggle(ledPort, ledPin);
}
