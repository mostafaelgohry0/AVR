/*
 * timer.h
 *
 *  Created on: May 6, 2020
 *      Author: mostafa
 */

#ifndef F_CPU
#define F_CPU 1000000UL
#endif


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#include "utils.h"
#include "types.h"


#define  PRESCALING 8

#define OVER_FLOW_TIME  ((F_CPU)/(255*PRESCALING ))



#endif /* TIMER_H_ */
