/*
 * spi.h
 *
 *  Created on: Jan 3, 2020
 *      Author: mostafa
 */

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL
#define DDR_SPI DDRB

#define DD_MOSI DDB5
#define DD_MISO DDB6
#define DD_SCK  DDB7

#define MOSI PB5
#define MISO PB6
#define SCK  PB7
#define SS   PB4







void spi_master_init();
void spi_slave_init();

void spi_master_transmit(unsigned char data);
unsigned char spi_slave_receive();




#endif /* SPI_H_ */
