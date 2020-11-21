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
#include "utils.h"
#include  "types.h"
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#define BAUD 9600
#define UBRR 25 //(F_CPU/(16*BAUD))-1
unsigned int i ;

void uart_init();
uint8  uart_recive_char();
void uart_sent_char (uint8  data);

//void set_seven( unsigned char x);
void set_reciver();
void set_transmitter();
void uart_sent_string(char *c);

#endif /* UART_H_ */
