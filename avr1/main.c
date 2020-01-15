#define F_CPU 1000000UL
//#include <avr/io.h>
//#include<util/delay.h>


#include <avr/io.h>
#include <util/delay.h>



int  main(void)
{

    DDRD &=~(1<<PD7);
	DDRA |= (1<<PA0);


   while(1){

    if(PIND&=(1<<PD7))
	   PORTA |=(1<<PA0);
     //  PORTA ^=(1<<PA0);
   //	_delay_ms(2000);
   //	PORTA = 0b00000000;
   else
    PORTA &=~(1<<PA0);
   //	_delay_ms(500);


   }

	return 0;
}


/*
 int  main(void)
{

   //DDRA = 0b11111111;
	DDRA |= (1<<PA0);
   // PORTA = 0b11111111;

   while(1){

   //	PORTA = 0b11111111;
	   PORTA |=(1<<PA0);
   	_delay_ms(2000);
   //	PORTA = 0b00000000;
    PORTA &=~(1<<PA0);
   	_delay_ms(500);


   }

	return 0;
}

 */



/*

int main(void){
	DDRA = 0b11111111;


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
       //buzzer
     PORTA = 0b00001000;
      _delay_ms(1000);

	}


	return 0;
}
*/
