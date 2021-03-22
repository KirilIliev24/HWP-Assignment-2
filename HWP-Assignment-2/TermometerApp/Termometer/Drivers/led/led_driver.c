/*
 * led_driver.c
 *
 * Created: 2/21/2021 4:04:23 PM
 *  Author: Kiril
 */ 

#include <avr/io.h>
#include "led_driver.h"
#include <stdbool.h>

void led_create()
{
	//Port A as output 
	DDRA = 0xff;

	//turn off all LEDs
	PORTA = 0xff;
}

//led_no is from 0 to 7
//state 1-ON state 0-OFF
void led_set(uint8_t led_no, uint8_t state)
{
	if (led_no < 0 || led_no > 7)
	{
		return;
	}
	else
	{
		if (state == 1)
		{
			PORTA &= ~(_BV(led_no));
		}
		else
		{
			PORTA |= _BV(led_no);
		}
	}
	
}

void set_logical_operators(uint8_t inputOne, uint8_t inputTwo)
{
	//AND
	bool ledOne = inputOne & inputTwo;
	led_set(7, ledOne);
	
	//OR
	bool ledTwo = inputOne | inputTwo;
	led_set(6, ledTwo); 
	
	//XOR
	bool ledThree = inputOne ^ inputTwo;
	led_set(5, ledThree);
	
	//NAND
	bool ledFour = !ledOne;
	led_set(4, ledFour);
	
	//NOR
	bool ledFive = !ledTwo;
	led_set(3, ledFive);
	
	//XNOR
	bool ledSix = !ledThree;
	led_set(2, ledSix);
}

void lightbar(uint8_t level)
{
	if(level < 1)
	{
		return;
	}
	
	for (uint8_t i = 0; i < level; i++)
	{
		led_set(i, 1);
	}
}