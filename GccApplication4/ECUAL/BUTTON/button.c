/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 


#include "button.h"

//initialize
// buttonInit skeletal.
/*
	Just call the DIO_init with the arguments along with value IN to initialize the pin on the port as input.
*/
void buttonInit(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort, buttonPin, IN);
}

//Button read
// buttonRead skeletal.
/*
	Just call the DIO_read with the arguments to get the value on the desired pin.
*/
void buttonRead(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value){
	DIO_read(buttonPort, buttonPin, value);
}
