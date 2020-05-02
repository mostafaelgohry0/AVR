/*
 * i2c.h
 *
 *  Created on: Jan 16, 2020
 *      Author: mostafa
 */

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <util/delay.h>
#include "utils.h"
#include "types.h"

//#undef F_CPU
//#define F_CPU 8000000
#define PRESCALER  1
#define SCK_FREQ  400000  // 400k hz
#define TWBR_VALUE  0x0c// (((F_CPU/SCK_FREQ)-16)/(2*PRESCALER))


void i2c_start();
void i2c_stop();
void i2c_init();
void i2c_write_addr(unsigned char addr);
void i2c_write_data(unsigned char data);
void i2c_slave_init(unsigned char addr);
unsigned char  i2c_read_data();
void i2c_ack();

#endif /* I2C_H_ */
