
#include "lcd.h"
#include "keypad.h"
uint8 out_char ;

int main(){

	lcd_init();
    test_lcd ();

 	return 0 ;
}


void test_lcd (){
	//uint8 c=0;
	uint32  ch =90;
	//uint8 pre_ch =0;

	while(1){

	///	while (ch<150){
			set_position(0, 2);
		lcd_write_number(ch);
		_delay_ms(2);
	//	lcd_write_number(786);
		ch++;
		//}

/*

	  ch=key_scan();

		if(pre_ch!=ch){
		  pre_ch = ch;
		    lcd_write_char(key_scan());
		    _delay_ms(100);

		    c++;
		    if(c==16){
			    lcd_command(BEGIN_FROM_FRIST_LINE);  // return to home
			    _delay_ms(2);
			    c=0;
		    }

	}
*/

	}

}



void lcd_init(){

	_delay_ms(20) ;    // display take around  15 ms to power on

    SET_PORT_VAL(LCD_DDR,0XFF);
    SET_BIT(DDRB,RS);
    SET_BIT(DDRB,RW);
    SET_BIT(DDRB,EN);

	lcd_command(EIGHT_BIT_TWO_LINE);                    // set lcd as 16*2  8 bit mode
	lcd_command(DISPALY_ON_CURSOR_BLINKING);   // set  display on
	lcd_command(AUTO_INCREMENT_LEFT_TO_RIGHT);    // set auto increment cursor
	lcd_command(CLEAR_DISPLAY);   // clear lcd
	_delay_ms(2);
	//lcd_command(0x1c);   // shift lcd right
	//lcd_command(0x18);   // shift lcd left
	lcd_command(BEGIN_FROM_FRIST_LINE);  // return to home
}


void lcd_command(uint8 cmd){

	Enable();
	SET_COMMAND_MODE();
	SET_WRITE_MODE();
	LCD_PORT = cmd;
}



void lcd_write_char(unsigned char data){

	Enable();
	SET_DATA_MODE();
	SET_WRITE_MODE();
	LCD_PORT = data;
}



void lcd_write_str( char* str) {
	int i;
	 for(i=0;str[i]!='\0';i++){
		 lcd_write_char(str[i]);
	 }
}



void set_position(uint8 x ,uint8 y){
    uint8 pos ;
    if((x==0)&&(y<16)){
    	pos=0x80;
    	pos+=y;
    	lcd_command(pos);
    }
    else if((x==1)&&(y<16)){
    	pos=0xC0;
    	pos+=y;
    	lcd_command(pos);
    }
    else {
    	lcd_command(BEGIN_FROM_FRIST_LINE);
    	lcd_write_str("invalid position");
    }
}



void lcd_write_number(int num ){
      int i ,c=9;
      uint8 data_arr[10];

	    while(num>=10){
	    	i=num%10;
	    	num-=i;
	    	num/=10;
	    	data_arr[c]=i+'0';
	    	c--;
	    }
	    data_arr[c]=num+'0';
	    for(i=c;i<=9;i++){

	   lcd_write_char(  data_arr[i]);
	    }

}


// THIS FUNCTIONS  FOR KEYPAD   BUT NOT USED


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

