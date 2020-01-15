
#include <avr/io.h>
#include <util/delay.h>


int main(){

	// disable jtag  and use port c
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	 // PA0--PA3 -rows     / PA4--PA7  -column
	 ///        out    in
	 ///        column   row
     // DDRA    1111     0000

	DDRB = 0xff;
	PORTB=0xff;

	DDRC = 0b11110000;


	while(1){

		 PORTC=0b11100000;

		 if(PINC==0b11101110)
		 	 PORTB=0b00000001;

		 else if(PINC==0b11101110)
			 PORTB=0b00000001;

		 else if(PINC==0b11101101)
			 PORTB=0b00000010;

		 else if(PINC==0b11101011)
		 	 PORTB=0b00000100;

		 else if(PINC==0b11100111)
		 	 PORTB=0b00000011;



		 PORTC=0b11010000;

		 if(PINC==0b11011110)
			 PORTB=0b00000001;

		 else if(PINC==0b11011110)
			 PORTB=0b00000001;

		 else if(PINC==0b11011101)
			 PORTB=0b00000010;

		 else if(PINC==0b11011011)
			 PORTB=0b00000100;

		 else  if(PINC==0b11010111)
			 PORTB=0b00000101;


		 PORTC=0b10111111;

		 if(PINC==0b10111110)
			 PORTB=0b00000001;

		 else if(PINC==0b10111110)
		     PORTB=0b00000001;

	     else if(PINC==0b10111101)
			 PORTB=0b00000010;

	      else if(PINC==0b10111011)
			 PORTB=0b00000100;

		  else if(PINC==0b10110111)
			 PORTB=0b00000011;


		 PORTC=0b01111111;

		 if(PINC==0b01111110)
			 PORTB=0b00000001;

		 else if(PINC==0b01111110)
			 PORTB=0b00000001;

		 else if(PINC==0b01111101)
			 PORTB=0b00000010;

	     else if(PINC==0b01111011)
			 PORTB=0b00000100;

		 else if(PINC==0b01110111)
			 PORTB=0b00000101;

	}


	return 0;
}
