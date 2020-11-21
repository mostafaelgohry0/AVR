/*
 * uart_test.c
 *
 *  Created on: Nov 7, 2020
 *      Author: mostafa
 */
#include "uart.h"
#include "seven_segment.h"

int main (){
   uart_init();

   //enable interrupt
   // SET_BIT(UCSRB,RXCIE);
   // sei();

    while(1){
       set_transmitter();
      //  set_reciver();
    }

	return 0;
}


void set_transmitter(){
	DDRA = 0X00;
	PORTA = 0xff;
	 while(1){
		 if((PINA&(1<<PA0))==0)
			 uart_sent_char('0');
		 else  if(GET_BIT(PINA,PA1)==0)
			 uart_sent_char('1');
		 else if(GET_BIT(PINA,PA2)==0)
			 uart_sent_char('2');
		 if((PINA&(1<<PA3))==0)
			 uart_sent_char('3');
		 else  if(GET_BIT(PINA,PA4)==0)
			 uart_sent_char('0');
	     else if(GET_BIT(PINA,PA5)==0)
	    	 uart_sent_char('5');
		 else
			 uart_sent_char('w');

	 }

}

void set_reciver(){
	DDRA = 0Xff;
	 while(1){
		 set_seven(uart_recive_char());
	 }

}
