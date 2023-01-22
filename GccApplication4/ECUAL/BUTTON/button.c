/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 


#include "button.h"


/************************************************************************/
/* Global variables                                                     */
/************************************************************************/
/*
	The following variables are to be used with the function buttonPressed to preserve the state of the buttons along the program.
*/
	/*This is a variable to indicate if the button is pressed(1) and preserve the same value(1) until it's released
	and that is for the objective of not sensing the long press as multiple presses.*/
	uint8_t pressed[NUMBER_OF_BUTTONS] = {0};

	/* This variable is to make sure that the  button is pressed for at least that amount of CONFIDENCE_LEVEL
	to avoid the button De-bouncing problem.*/
	int pressed_confidence_level[NUMBER_OF_BUTTONS] = {0};

	/* This variable is to make sure that the  button is released for at least that amount of CONFIDENCE_LEVEL
	to avoid the button De-bouncing problem.*/
	int released_confidence_level[NUMBER_OF_BUTTONS] = {0};


/************************************************************************/
/* Function implementations                                             */
/************************************************************************/
//initialize button state, input or output.
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


/* 
	This function mainly is to check if the  button is pressed with a specific CONFIDENCE_LEVEL to avoid the De-bouncing problem
	and to check that it has 4 parameters:
		* buttonNumber -> which takes the number of button that we want to check its state
		* buttonPort -> the port that the button is connected to.
		* buttonPin -> the number of the pin that the button is connected to.
		* value -> a pointer to a variable to assign the state of the button to it.
*/

void buttonPressed(uint8_t buttonNumber, uint8_t buttonPort, uint8_t buttonPin, uint8_t *value){

	// Read the state of the button by passing the variable value by reference.
	buttonRead(buttonPort, buttonPin, value);
		
	// Check if the button is pressed(value = 1) or not(value = 0).
	if(*value) 
	{
		//The button is pressed(value = 1).
		/* There are 2 cases here
				* value = 1 and pressed = 1 -> the button is pressed and let's toggle the leds based on that.
				* value = 1 and pressed = 0 -> Long press, don't toggle the leds anymore.
		*/
			
		pressed_confidence_level[buttonNumber]++; // Incrementing the value each iteration to check on the button if it's pressed at least the  CONFIDENCE_LEVEL.
		if(pressed_confidence_level[buttonNumber] >= CONFIDENCE_LEVEL)
			{
				if(pressed[buttonNumber] == 0) // This check to indicate that if it's a new press of just a long one!
				{
					pressed[buttonNumber] = 1; // that's a guard to stop the LEDs from toggling multiple times in the long presses.
					return;
				}
				pressed_confidence_level[buttonNumber] = 0;
			}
	}
	else			
	{
		/*The button is either not pressed(value = 0) and 
			*  we just preserve the value of pressed = 1 and nothing more or
			* reseting the pressed to be 1 after a long press.
		*/	
		released_confidence_level[buttonNumber]++;
		if(released_confidence_level[buttonNumber]>= CONFIDENCE_LEVEL)		
			{
				pressed[buttonNumber] = 0;
				released_confidence_level[buttonNumber] = 0;
			}
	}
	
	// Just assigning a 0 for the value as if didn't return when the pressed_confidence_level >= CONFIDENCE_LEVEL, so we will consider it unpressed.
	*value = 0;
}