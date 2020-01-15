/*
 * uart.h
 *
 *  Created on: Dec 24, 2019
 *      Author: mostafa
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL
#define BAUD 9600
#define UBRR 25 //(F_CPU/(16*BAUD))-1

void uart_init();
void uart_recive();
void uart_sent();


#endif /* UART_H_ */
