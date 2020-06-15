/*
 * interrupt.c
 *
 *  Created on: Feb 5, 2020
 *      Author: mostafa
 */


#include "interrupt.h"


ISR(INT0_vect){
	 SET_BIT(PORTB,PB0);
	 _delay_ms(2000);
	 CLEAR_BIT(PORTB,PB0);

}

int main (void){

    SET_BIT_DIRECTION('O',DDRA,PA0);
    SET_BIT_DIRECTION('O',DDRB,PB0);
    SET_BIT_DIRECTION('I',DDRD,PD6);
   // set PD2 as input
    SET_BIT_DIRECTION('I',DDRD,PD2);

	SET_BIT(PORTD,PD6);
	SET_BIT(PORTD,PD2);

	//enable interrupt
	SET_BIT(GICR,INT0);

    sei();

while(1){

	 TOGGLE_BIT(PORTA,PA0);
	 _delay_ms(500);

	 if(GET_BIT(PIND,PD6)==0)
		 SET_BIT(PORTB,PB0);
	 else
	     CLEAR_BIT(PORTB,PB0);

}



	return 0;
}



