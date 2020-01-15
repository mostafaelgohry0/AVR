
#include<avr/io.h>
#include<util/delay.h>
#include "stack.h"
#include<math.h>

void lcd_init();    // initialization   the lcd
void lcd_write_char(unsigned char data);   // write data
void lcd_write_str( char* str);   // write data
void lcd_write_number(int num );   // write data
void lcd_command(unsigned char cmd);  // sent command
void print_number();

unsigned char get_char();

unsigned char get_char2();

unsigned char key_arr[4][4]={ {'1','2','3','A'},
		 	 	 	  {'4','5','6','B'},
	 	 	 	 	  {'7','8','9','C'},
	 	 	 	 	  {'*','0','#','D'}};




int main(){
	// disable jtag  and use port c
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	DDRC = 0b11110000;
	//printf("%d\n",sizeof(y));

	DDRA = 0b11111111;   // set port A  for  data
	DDRB = 0b11111111;    // set port B  for command
	DDRD = 0b11111110;
	PORTC = 0B11111111;





	lcd_init();
	intial_stack(20);
	//lcd_write_str("lcd init ok");

	 unsigned char my_char,last_char ;

	last_char='p';

 while(1){
	// last_char='p';
	   my_char = get_char();

	   if(my_char==last_char){
		  my_char='t';
	  }
     asm("NOP");
	  last_char= get_char();
	   switch(my_char){

	   case ('n'):
			   break;

	   case ('t'):
	  			   break;

	   default:{
		lcd_write_char(my_char);
		 break;
	   }

	}
 }


 	return 0 ;
}



int  insert_data(){

	int c =1;
	int i;
	unsigned int r;
	int j;
	 unsigned int x =12354;
	char arr[20];
	char ch;
	i=0;
	while (c==1){

		if(x<10){

		  c=0;
		  //break;
		}
		 for (j=0;j<10;j++){
			 r = x-j;
			 if(r%10==0){
				 arr[i]= j + '0';
                  push(arr[i]) ;
				// lcd_write_char(arr[i]);
				 x = x - j;
				 x/=10;
			     i++;
			     j=10;
			 }
		 }
	}

	return i;

}



void print_number(){
    int j ;
    char ch;
    int i;
    i= insert_data();
	 for(j=0;j<i;j++){
				ch =  pop();
				 lcd_write_char(ch);

			 }


}
void lcd_command(unsigned char cmd){

	PORTA = cmd;   // sent cmd by data lines

	PORTB = 0b11111100;   // set rs=0 , rw 0 ,en 1
	 _delay_ms(1);
	    PORTB = 0b11111000;   // set rs=1 , rw 0 ,en 0
	    _delay_ms(1);



}





void lcd_init(){

	lcd_command(0x38);  // set lcd as 16*2  8 bit mode
	lcd_command(0x0C);  // set  display on
	lcd_command(0x06);    // set auto increment cursor
	lcd_command(0x01);   // clear lcd
	//lcd_command(0x1c);   // shift lcd right
	//lcd_command(0x18);   // shift lcd left


	lcd_command(0x80);  // return to home
}

void lcd_write_char(unsigned char data){

	PORTA = data;   // sent cmd by data lines

    PORTB = 0b11111101;   // set rs=1 , rw 0 ,en 1
    _delay_ms(1);
    PORTB = 0b11111001;   // set rs=1 , rw 0 ,en 0
  //  _delay_ms(1);


}

void lcd_write_str( char* str) {
	int i;
	 for(i=0;str[i]!='\0';i++){
		 lcd_write_char(str[i]);
	 }

}

void lcd_write_number(int num ){

	    PORTA = num;   // sent cmd by data lines

	    PORTB = 0b11111101;   // set rs=1 , rw 0 ,en 1
	    _delay_ms(1);
	    PORTB = 0b11111001;   // set rs=1 , rw 0 ,en 0
	  //  _delay_ms(1);

}






unsigned char get_char(){

//	_delay_ms(20);



	 PORTC=0b01111111;

			 if(PINC==0b01111110)
				  return 'A';
			 else if(PINC==0b01111110)
				  return 'A';
			 else if(PINC==0b01111101)
				  return 'B';
		     else if(PINC==0b01111011)
		    	  return 'C';

			 else if(PINC==0b01110111)
				  return 'D';




		 PORTC=0b11101111;

		 if(PINC==0b11101110)
			  return '1';

		 else if(PINC==0b11101110)
			  return '1';

		 else if(PINC==0b11101101)
			  return '4';

		 else if(PINC==0b11101011)
			  return '7';

		 else if(PINC==0b11100111)
			   return '*';



		 PORTC=0b11011111;

		 if(PINC==0b11011110)
			  return '2';

		 else if(PINC==0b11011110)
			  return '2';
		 else if(PINC==0b11011101)
			  return '5';
		 else if(PINC==0b11011011)
			  return '8';

		 else  if(PINC==0b11010111)
			  return '0';


		 PORTC=0b10111111;

		 if(PINC==0b10111110)
			  return '3';
		 else if(PINC==0b10111110)
			  return '3';

	     else if(PINC==0b10111101)
	    	  return '6';

	      else if(PINC==0b10111011)
	    	  return '9';

		  else if(PINC==0b10110111)
			  return '#';



		 else return 'n';


}




unsigned char get_char2(){

	_delay_ms(20);



	 PORTC=0b01111111;

	 switch(PINC){

	 case 0b01111110 :
		 return 'A';
		 break;

	 case 0b01111101 :
		  return 'B';
		  break;

	 case 0b01111011 :
		  return 'C';
		  break;

	 case 0b01110111 :
		  return 'D';
		  break;

	 default :
		 return 'n';
		 break;

	 }


		 PORTC=0b11100000;


		 switch(PINC){

		 case 0b11101110 :
			 return '1';
			 break;

		 case 0b11101101 :
			  return '4';
			  break;

		 case 0b11101011 :
			  return '7';
			  break;

		 case 0b11100111 :
			  return '*';
			  break;

		 }



		 switch(PINC){

		 case 0b11011110 :
			 return '2';
			 break;

		 case 0b11011101 :
			  return '5';
			  break;

		 case 0b11011011 :
			  return '8';
			  break;

		 case 0b11010111 :
			  return '0';
			  break;

		 }



		 PORTC=0b10111111;


		 switch(PINC){

		 case 0b10111110 :
			 return '3';
			 break;

		 case 0b10111101 :
			  return '6';
			  break;

		 case 0b10111011 :
			  return '9';
			  break;

		 case 0b10110111 :
			  return '#';
			  break;

		 }

		  return 'n';


}

