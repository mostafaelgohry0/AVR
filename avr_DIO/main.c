/*
 * main.c
 *
 *  Created on: Sep 11, 2019
 *      Author: mostafa
 */
//#define F_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRA = 0b11111111;
	DDRD = 0b11111111;


	while(1){
	// turn off all
	PORTA = 0b00000000;
	_delay_ms(1000);
	//led 1
	PORTA = 0b00000001;
    _delay_ms(1000);
    //led 2
    PORTA = 0b00000010;
    _delay_ms(1000);
    //led 3
    PORTA = 0b00000100;
    _delay_ms(1000);
       //led4
    PORTA = 0b00001000;
    _delay_ms(1000);



    // number 0
	PORTD = 0b10111111;
	_delay_ms(2000);
	// number 1
	PORTD = 0b10000110;
    _delay_ms(2000);
    //  number 2
    PORTD = 0b11011011;
    _delay_ms(2000);
    // number 3
    PORTD = 0b11001111;
    _delay_ms(2000);
     // number 4
    PORTD = 0b11100110;
    _delay_ms(2000);
	// number 5
	PORTD = 0b11101101;
    _delay_ms(2000);
    //number 6
    PORTD = 0b11111101;
    _delay_ms(2000);
    //number 7
    PORTD = 0b10000111;
    _delay_ms(2000);
       //number 8
    PORTD = 0b11111111;
    _delay_ms(2000);
    // number 9
	PORTD = 0b11101111;
	_delay_ms(2000);
	// dot
	PORTD = 0b10000000;
    _delay_ms(2000);



	}


	return 0;
}

