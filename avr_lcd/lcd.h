/*
 * lcd.h
 *
 *  Created on: Jun 15, 2020
 *      Author: mostafa
 */

#ifndef LCD_H_
#define LCD_H_


#include<avr/io.h>
#include<util/delay.h>


#define Enable( )  SET_BIT(PORTB,EN);\
_delay_ms(1);\
CLEAR_BIT(PORTB,EN);


#define  SET_COMMAND_MODE()  (CLEAR_BIT(PORTB,RS))
#define  SET_DATA_MODE()    (SET_BIT(PORTB,RS))

#define  SET_WRITE_MODE()  (CLEAR_BIT(PORTB,RW))
#define  SET_READ_MODE ()  (SET_BIT(PORTB,RW))





#define EN PB2      //  enable pin
#define RW PB1      //  read  write
#define RS PB0      //  register select

#define LCD_PORT  PORTA
#define LCD_DDR   DDRA


// set lcd commands
#define CLEAR_DISPLAY  							                            ( 0X01)

#define SHIFT_CURSOR_TO_LEFT 					                    ( 0X10 )
#define SHIFT_CURSOR_TO_RIGHT                                    ( 0X14 )

#define SHIFT_ENTIRE_DISPLAY_TO_LEFT                       ( 0X18 )
#define SHIFT_ENTIRE_DISPLAY_TO_RIGHT                   ( 0X1C )

#define BEGIN_FROM_FRIST_LINE                                     ( 0X80 )
#define BEGIN_FROM_SECAND_LINE                               ( 0XC0 )

#define DISPALY_ON_CURSOR_OFF                                   ( 0X0C )
#define DISPALY_ON_CURSOR_BLINKING                      ( 0X0E )

#define AUTO_INCREMENT_LEFT_TO_RIGHT                  ( 0X06 )

#define EIGHT_BIT_ONE_LINE                                              ( 0X30 )
#define FOUR_BIT_ONE_LINE                                               ( 0X20 )
#define EIGHT_BIT_TWO_LINE                                             ( 0X38 )
#define FOUR_BIT_TWO_LINE                                              ( 0X28 )



// functions
void test_lcd ();

void lcd_init();    // initialization   the lcd
void lcd_write_char(unsigned char data);   // write data
void lcd_write_str( char* str);   // write data
void lcd_write_number(int num );   // write data
void lcd_command(unsigned char cmd);  // sent command

void set_position(unsigned char x ,unsigned char y);
void print_number();


unsigned char get_char();

unsigned char get_char2();






#endif /* LCD_H_ */
