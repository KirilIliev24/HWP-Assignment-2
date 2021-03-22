/*
 * Termometer.c
 *
 * Created: 3/18/2021 1:06:05 PM
 * Author : kiril
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "Drivers/led/led_driver.h"
#include "Drivers/Termometer/Termometer.h"
#include "Drivers/Timer/Timer.h"

int main(void)
{
	sei();
	timer_init();
	led_create();
	termometer_create();
		
    /* Replace with your application code */
    while (1) 
    {
    }
	
	return 0;
}

