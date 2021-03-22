/*
 * led_driver.h
 *
 * Created: 2/21/2021 4:04:44 PM
 *  Author: kiril
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

void led_create();
void led_set(uint8_t led_no, uint8_t state);
void set_logical_operators(uint8_t inputOne, uint8_t inputTwo);
void lightbar(uint8_t level);

#endif /*LED_DRIVER_H_*/