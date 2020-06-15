/*
 * avr_keypad.h
 *
 *  Created on: Jun 14, 2020
 *      Author: mostafa
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#include "utils.h"
#include "types.h"

#define  key_pin   PINB
#define  key_port   PORTB
#define  key_ddr   DDRB

typedef enum key_pins{
	col4,
	col3,
	col2,
	col1,
	row4,
	row3,
	row2,
	row1

}key_pins;

// function  declaration

uint8  key_scan();
void  test_key();


#endif /* KEYPAD_H_ */
