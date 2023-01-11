/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 


#include "dio.h"
// global variables
// function definitions.

// DIO_init skeletal.
/*
	1- Check on the port number.
	2- Based on the direction, assign 1 to the pin on DDRA if output and 0 if input.
*/
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) // initialize DIO direction
{
	// First check on the port number to apply changes to the desired one.
	switch(portNumber){
		case PORT_A:
			if(direction == IN) // Now this is to check on the direction.
			{
				DDRA &= ~(1<<pinNumber); //Input(Assign 0 to the pin if it's input bin).
			}
			else if(direction == OUT)
			{
				DDRA |= (1<<pinNumber); // output(Assign 1 to the pin if it's input bin).
			}
			else
			{
				//Error handling technique.
			}
			break;
		
		case PORT_B:
			if(direction == IN)
			{
				DDRB &= ~(1<<pinNumber); //Input
			}
			else if(direction == OUT)
			{
				DDRB |= (1<<pinNumber); // output
			}
			else
			{
				//Error handling technique.
			}
			break;
			
		case PORT_C:
			if(direction == IN)
			{
				DDRC &= ~(1<<pinNumber); //Input
			}
			else if(direction == OUT)
			{
				DDRC |= (1<<pinNumber); // output
			}
			else
			{
				//Error handling technique.
			}
			break;
		
		case PORT_D:
			if(direction == IN)
			{
				DDRD &= ~(1<<pinNumber); //Input
			}
			else if(direction == OUT)
			{
				DDRD |= (1<<pinNumber); // output
			}
			else
			{
				//Error handling technique.
			}
			break;
	}
}

// DIO_write skeletal.
/*
	1- Check on the port number.
	2- Based on the value, assign 1 to the pin on PORTA if HIGH and 0 if LOW.
*/
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value) // write data to DIO
{
	switch(portNumber){
		case PORT_A:
			if(value == LOW)
			{
				PORTA &= ~(1<<pinNumber); //write 0
			}
			else if(value == HIGH)
			{
				PORTA |= (1<<pinNumber); // write 1
			}
			else
			{
				//Error handling technique.
			}
			break;
	
		case PORT_B:
			if(value == LOW)
			{
				PORTB &= ~(1<<pinNumber); //write 0
			}
			else if(value == HIGH)
			{
				PORTB |= (1<<pinNumber); // write 1
			}
			else
			{
				//Error handling technique.
			}
			break;
	
		case PORT_C:
			if(value == LOW)
			{
				PORTC &= ~(1<<pinNumber); //write 0
			}
			else if(value == HIGH)
			{
				PORTC |= (1<<pinNumber); // write 1
			}
			else
			{
				//Error handling technique.
			}
			break;
	
		case PORT_D:
			if(value == LOW)
			{
				PORTD &= ~(1<<pinNumber); //write 0
			}
			else if(value == HIGH)
			{
				PORTD |= (1<<pinNumber); // write 1
			}
			else
			{
				//Error handling technique.
			}
			break;
	}
}

// DIO_toggle skeletal.
/*
	1- Check on the port number.
	2- The value on the specified port is gonna be inverted using X-OR function.
*/
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber) //toggle DIO
{
	switch(portNumber){
		case PORT_A:
			PORTA ^= (1<<pinNumber); // write 1
			break;
		
		case PORT_B:
			PORTB ^= (1<<pinNumber); // write 1
			break;
		
		case PORT_C:
			PORTC ^= (1<<pinNumber); // write 1
			break;
		
		case PORT_D:
			PORTD ^= (1<<pinNumber); // write 1
			break;
	}
}


// DIO_read skeletal.
/*
	1- Check on the port number.
	2- Read the value on the specified port using GET_BIT directive.
*/
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value) //read DIO
{
	switch(portNumber)
	{
		case PORT_A:
			//*value = (PINA &(1<<pinNumber))>>pinNumber; // GET STATE -> READ BIT
			*value = GET_BIT(PINA, pinNumber);
			break;
		
		case PORT_B:
			//*value = (PINB &(1<<pinNumber))>>pinNumber; // GET STATE -> READ BIT
			*value = GET_BIT(PINB, pinNumber);
			break;
		
		case PORT_C:
			//*value = (PINC &(1<<pinNumber))>>pinNumber; // GET STATE -> READ BIT
			*value = GET_BIT(PINC, pinNumber);
			break;
		
		case PORT_D:
			//*value = (PIND &(1<<pinNumber))>>pinNumber; // GET STATE -> READ BIT
			*value = GET_BIT(PIND, pinNumber);
			break;
		
		default:
			//Error handling.
			break;
	}
}

