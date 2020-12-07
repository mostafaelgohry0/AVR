/*
 * timer.c
 *
 *  Created on: May 6, 2020
 *      Author: mostafa
 */

#include "timer.h"
#include  "ADC.h"
#include "lcd.h"
volatile uint64 i_value;


void time_delay_ms(uint64 mytime){
	// convert  time from ms to s
     uint64 time_ratio  =  mytime  /1000;

	uint64 over_flow_count =(sint64)  (time_ratio* OVER_FLOW_TIME );

	//set timer with normal mode and with  prescaling 8
	SET_BIT(TCCR0,CS01);

	//initialize the TCNT0
	TCNT0 = 0;

    while ( over_flow_count>0){
    	while((GET_BIT(TIFR,TOV0))==0);

    	SET_BIT(TIFR,TOV0); 	//reset TOV0 timer overflow flag
	    TCNT0 = 0;
	    over_flow_count --;
       }
    }



void interrupt_delay_ms(uint64 mytime){


	 uint64 time_ratio  =  mytime  /1000;

	i_value =(uint64)  (time_ratio* OVER_FLOW_TIME );

	//set timer with normal mode and with  prescaling 8
	SET_BIT(TCCR0,CS01);

	//initialize the TCNT0
	TCNT0 = 0;
    while (i_value >0);
}

ISR(TIMER0_OVF_vect){

     i_value--;
    TCNT0 = 0;

}



void timer_pwm(){

	ADC_init();
	lcd_init();

	// set mode
	 SET_BIT(TCCR0,WGM00);
	 SET_BIT(TCCR0,WGM01);

  // SET clock prescaling    8 bit
	 //	SET_BIT(TCCR0,CS00);
		//SET_BIT(TCCR0,CS02);
		SET_BIT(TCCR0,CS01);

		// set output compare match
		SET_BIT(TCCR0,COM01);

		SET_BIT(DDRB,PB3);
	//	OCR0 = 100;


		// disable jtag  and use port c
			MCUCSR = (1<<JTD);
			MCUCSR = (1<<JTD);


		while(1){


		OCR0 =(.25*read_ADC_pin(PA0));

			set_position(0, 5);
			lcd_write_number(OCR0);
		     //_delay_ms(700);
			/*
			 while(OCR0<255){
				 OCR0++;
				 _delay_ms(10);
			 }

			 _delay_ms(1000);
			 while(OCR0>0){
				 OCR0--;
				 _delay_ms(10);
			 }

			  _delay_ms(1000);

*/
		}



}
void test_timer(){

	lcd_init();
//Enable interrupt
//   	i_value=3136;
SET_BIT(TIMSK,TOIE0);
	//enable global  interrupt
sei();
	DDRD =0XFF;
//	TCNT0 = 0;

while(1){


PORTD=0xff;
set_position(0, 2);
lcd_write_str("led on ");
//time_delay_ms(1000);
interrupt_delay_ms(2000);
lcd_command(CLEAR_DISPLAY);
set_position(0, 2);

lcd_write_str("led off ");
PORTD= 0x00;
time_delay_ms(1000);
lcd_command(CLEAR_DISPLAY);
}


}

int main(){

  test_timer();
//	timer_pwm();


	return 0;
}
