/*
 * seven_segment.h
 *
 *  Created on: Jun 14, 2020
 *      Author: mostafa
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include <avr/io.h>
#include <util/delay.h>

#include "utils.h"
#include "types.h"


#define  SEVEN_PORT  PORTA


// function  declaration
void set_seven(uint8 x);


#endif /* SEVEN_SEGMENT_H_ */
