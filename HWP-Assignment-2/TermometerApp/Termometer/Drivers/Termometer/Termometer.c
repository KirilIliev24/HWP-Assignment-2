/*
 * Termometer.c
 *
 * Created: 3/18/2021 1:13:01 PM
 *  Author: kiril
 */ 

//#include <stdio.h>
//#include <stdlib.h>
//#include "Termometer.h"
#include "../led/led_driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile float adcLevel = 0;
volatile float voltage = 0.00f;
volatile int8_t temperature = 0;

void startConversion()
{
	//start conversion
	ADCSRA |= _BV(ADSC);
	//while(ADCSRA & _BV(ADSC));
}

void setupADC()
{
	//MUX 0, 1, 2, 5 are set because we use ADC15 which is 100111
	ADMUX |= _BV(REFS0) | _BV(MUX0) | _BV(MUX1) | _BV(MUX2);
	ADCSRB |= _BV(MUX5); 
	
	//ADEN is enabling the ADC conversion
	//ADATE enable auto trigger
	//ADIE ISR is called when the conversion is done                        
	//ADPS0 ADPS1 ADPS2 are for the division factor 128
	ADCSRA |= _BV(ADEN) | _BV(ADIE) | _BV(ADATE) | _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2);
	
	//auto trigger connected to timer 1
	ADCSRB |= _BV(ADTS0) | _BV(ADTS2); 
	startConversion();
}

void termometer_create()
{
	//set port G bit 0 to output
	DDRG |= _BV(PG0);
	
	//enable tmp sensor
	PORTG |= _BV(PG0);
		
	//sei();
	setupADC();
	
	//set port k bit 7 to input
	DDRK &= ~_BV(PK7);
}

void Show_leds(int8_t temp)
{
		if(temp < 18)
		{
			lightbar(0);
		}
		else if (temp > 25)
		{
			lightbar(8);
		}
		else
		{
			int8_t level = temp % 17;
			lightbar(level);
		}
}

ISR(ADC_vect)
{
	adcLevel = ADC;
	//calculate temperature
	voltage = (adcLevel * 5.0) / 1024.0;
	temperature = (voltage - 0.5) * 100;
	Show_leds(temperature);
	TIFR1 |= _BV(OCR1B); 
}