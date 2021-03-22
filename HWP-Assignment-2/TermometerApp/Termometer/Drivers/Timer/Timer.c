/*
 * Timer.c
 *
 * Created: 3/19/2021 4:21:44 PM
 *  Author: kiril
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer.h"


//timer for 1 sec
void timer_init()
{	
	TCCR1A |= _BV(WGM12);
	
	//prescaler 256
	TCCR1B |= _BV(CS12);
	
	OCR1A = 62500;
	
	//when timer output compare matches B interrupt called 
	TIMSK1 |= _BV(OCIE1B);
}

ISR(TIMER1_COMPB_vect)
{
	
}