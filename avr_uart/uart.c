

#include "uart.h"
volatile char data ;

int main(){
	uart_init();
	DDRD &=~(1<<PD7);
	DDRA |= (1<<PA0);

	while(1){


	uart_recive();





     /// sent value
	//	if(PIND&=(1<<PD7))
		//	uart_sent();
	}

	return 0;
}



void uart_init(){

	// Enable  the receiver  and the transmitter
	UCSRB = (1<<RXEN)|(1<<TXEN);

	//set 2 stop bit  8 data bit
	UCSRC = (1<<URSEL)|(3<<UCSZ0);//|(1<<USBS);

	UBRRH = (unsigned char )(UBRR>>8);
	UBRRL = (unsigned char )UBRR;

}

//////////////////////////

void uart_sent(){

	while(!(UCSRA&(1<<UDRE)));{
		UDR='A';
	 _delay_ms(500);
	}


}

//////////////////////////

void uart_recive(){

	while(!(UCSRA&(1<<RXC)));{
		data = UDR;

		 if(data =='A')
			 	PORTA ^=(1<<PA0);


	}


}

