/*
 * ADC.h
 *
 *  Created on: May 9, 2020
 *      Author: mostafa
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "utils.h"
#include "types.h"

void ADC_init();
uint8 read_ADC_pin(uint8 pin_number);
void test_ADC();


#endif /* ADC_H_ */
