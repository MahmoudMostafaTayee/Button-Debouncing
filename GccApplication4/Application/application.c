/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 

#include "application.h"
#define CONFIDENCE_LEVEL 500 // A confidence level for the de-bouncing problem.

void appInit(){
	// Initializing of the pin for the 1st led to be output.
	LED_init(LED_1_PORT, LED_1_PIN);	
	
	// Initializing of the pin for the 2nd led to be output.
	LED_init(LED_2_PORT, LED_2_PIN);	
	
	/* Initializing the 2nd led to be ON as state of both of them is initially OFF
	which encounters the main idea of the project which them to be the opposite of each others.*/
	LED_on(LED_2_PORT, LED_2_PIN);		
	
	// Initializing the pin of the button to be input.
	buttonInit(BUTTON_1_PORT, BUTTON_1_PIN); //
}



void appStart(){
	 /*This is a variable to indicate if the button is pressed(0) and preserve the same value(0) until it's released
	 and that is not sense the long press as multiple presses.*/
	uint8_t pressed = 1;
	
	// This is a value for getting the current state of the button(pressed or not).
	uint8_t value;
	
	/* This variable is to make sure that the  button is pressed for at least that amount of CONFIDENCE_LEVEL
	 to avoid the button de-bouncing problem.*/
	int pressed_confidence_level = 0;
	
	/* This variable is to make sure that the  button is released for at least that amount of CONFIDENCE_LEVEL
	 to avoid the button de-bouncing problem.*/
	int released_confidence_level = 0;
	
	while(1)
	{
		// Read the state of the button by passing the variable value by reference.
		buttonRead(BUTTON_1_PORT, BUTTON_1_PIN, &value);
		
		// Check if the button is pressed(value = 1) or not(value = 0).
		if(value) 
		{
			//The button is pressed(value = 1).
			/* There are 2 cases here
					* value = 1 and pressed = 1 -> the button is pressed and let's toggle the leds based on that.
					* value = 1 and pressed = 0 -> Long press, don't toggle the leds anymore.
			*/
			
			pressed_confidence_level++; // Incrementing the value each iteration to check on the button if it's pressed at least the  CONFIDENCE_LEVEL.
			if(pressed_confidence_level >= CONFIDENCE_LEVEL)
				{
					if(pressed) // This check to indicate that if it's a new press of just a long one!
					{
						pressed = 0; // that's a guard to stop the leds from toggling multiple times in the long presses.
						LED_toggle(LED_1_PORT, LED_1_PIN); // Toggle the 1st led.
						LED_toggle(LED_2_PORT, LED_2_PIN); // Toggle the 2nd led.
					}
					pressed_confidence_level = 0;
				}
		}
		else			
		{
			/*The button is either not pressed(value = 0) and 
				*  we just preserve the value of pressed = 1 and nothing more or
				* reseting the pressed to be 1 after a long press.
			*/	
			released_confidence_level++;
			if(released_confidence_level>= CONFIDENCE_LEVEL)		
				{
					pressed = 1;
					released_confidence_level = 0;
				}
		}
	}
}