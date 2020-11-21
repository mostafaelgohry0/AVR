#include "uart.h"

//unsigned char udr_data;

void uart_init(){


	// Enable  the receiver  and the transmitter
    SET_BIT(UCSRB,RXEN);
    SET_BIT(UCSRB,TXEN);

	 //set 2 stop bit  8 data bit
UCSRC= (1<<URSEL)|(3<<UCSZ0)|(1<<USBS);


	UBRRH = (uint8 )(UBRR>>8);
	UBRRL =  (uint8 )UBRR;

}



void uart_sent_char(uint8  data){

	while(!(UCSRA&(1<<UDRE)));{
		UDR=data;
	}

}

//////////////////////////

uint8 uart_recive_char(){

	while(!(UCSRA&(1<<RXC)));
	return UDR;
}

void uart_sent_string(char *c){

	// static unsigned int i =0;
	 //char c2 = {'1','2','3','4','5'};
	 /*
	while(1){

	 while(c2[i]!='5'){
		 uart_sent(c2[i]);
		 i++;
		 _delay_ms(500);
	 }

	 i=0;

	}
*/
}

ISR(USART_RXC_vect){

	//while(!(UCSRA&(1<<RXC)));
 //	udr_data =UDR;

//set_seven('0');


//PORTA =UDR;
TOGGLE_BIT(PORTB,PB0);
_delay_ms(3000);
SET_BIT(UCSRB,RXC);
// char 	udr_data1;
	//while(!(UCSRA&(1<<UDRE)));
	    	 	//udr_data1 =UDR;
	    	 	//UDR = udr_data1;
	    	 	//set_seven('0');
//while(!(UCSRA&(1<<UDRE)));

 //UDR='9';


}

