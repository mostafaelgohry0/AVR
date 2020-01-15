/*
 * lcd.h
 *
 *  Created on: Nov 22, 2019
 *      Author: mostafa
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include<util/delay.h>

#define EN PB2      //  enable pin
#define RW PB1      //  read  write
#define RS PB0      //  register select

#define DATA_PORT  PORTA
#define DATA_DDR   DDRA

// set lcd commands

#define CLEAR_DISPLAY  							  0X01
#define SHIFT_CURSOR_TO_LEFT 					  0X10
#define SHIFT_CURSOR_TO_RIGHT                     0X14
#define SHIFT_ENTIRE_DISPLAY_TO_LEFT              0X18
#define SHIFT_ENTIRE_DISPLAY_TO_RIGHT             0X1C
#define BEGIN_FROM_FRIST_LINE                     0X80
#define BEGIN_FROM_SECAND_LINE                    0XC0
#define DISPALY_ON_CURSOR_OFF                     0X0C
#define DISPALY_ON_CURSOR_BLINKING                0X0E
#define AUTO_INCREMENT_LEFT_TO_RIGHT              0X06
#define EIGHT_BIT_ONE_LINE                        0X30
#define FOUR_BIT_ONE_LINE                         0X20
#define EIGHT_BIT_TWO_LINE                        0X38
#define FOUR_BIT_TWO_LINE                         0X28




void lcd_init();
void lcd_command();

#endif /* LCD_H_ */
