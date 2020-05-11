/*
 * ADC.c
 *
 *  Created on: May 9, 2020
 *      Author: mostafa
 */

#include "ADC.h"

#define F_CPU 1000000UL
volatile uint8 data;

int main (){

	test_ADC();

	return 0;
}


void ADC_init(){
	//ENABLE ADC  AND
	SET_BIT(ADCSRA,ADEN);

	// set prescaler with 64
	ADCSRA |= (1<<ADPS1)|(1<<ADPS0);

	// set voltage reference  at AVCC 5V
	//SET_BIT(ADMUX,REFS0);

}


uint8 read_ADC_pin(uint8 pin_number){

    //enable 8 bit prescaler
	SET_BIT(ADCSRA,ADLAR);


	//select pin number
	ADMUX =pin_number;
	//SET_BIT(ADMUX,pin_number);

	// start conversion
	SET_BIT(ADCSRA,ADSC);

	//wait until end of conversion
	while(GET_BIT(ADCSRA,ADIF)==0);

	data = ADCH;
	return data;
}


void test_ADC(){
	ADC_init();
		DDRB =0XFF;
		DDRA=0X00;

	while(1){


		PORTB = read_ADC_pin(PA4);
	}

}
