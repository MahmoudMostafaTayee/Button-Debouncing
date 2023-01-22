/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 

#include "application.h"

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
	 while(1){
		 uint8_t value;
		 buttonPressed(BUTTON_1, BUTTON_1_PORT, BUTTON_1_PIN, &value); // Check if the button is pressed(value = 1) or released(value = 0)
		 if(value) //Act up on the button press.
		 {
			 // Toggle both LEDs if the button is pressed.
			 LED_toggle(LED_1_PORT, LED_1_PIN);
			 LED_toggle(LED_2_PORT, LED_2_PIN);
		 }
			 
	 }
}