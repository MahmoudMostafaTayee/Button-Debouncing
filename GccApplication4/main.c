/*
 * GccApplication4.c
 *
 * Author: Mahmoud Mostafa Tayee
 */ 


//#include <avr/io.h>
//#include<util/delay.h>
//#include "ECAL/DIO/dio.h"
#include "Application/application.h"


int main(void)
{
	// Let's call the function that will initialize the beginning state of the project.
	appInit();
	// Now calling the program to run after setting the initial state.
	appStart();
}

