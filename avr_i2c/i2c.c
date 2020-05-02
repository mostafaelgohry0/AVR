#include "i2c.h"

void test_master(){
	int i =0;
	DDRA=0X00;
	DDRB =0XFF;
	PORTA =0XFF;
	i2c_init();
		while(1){
			i++;
		_delay_ms(1000);
		i2c_start();
		i2c_write_addr(0x20);

			i2c_write_data('b');
		i2c_stop();
		}
}

void test_slave(){
	DDRA = 0XFF;
	i2c_slave_init(0x20);
	i2c_init();
    while(1){
    	 i2c_ack();
	if(i2c_read_data()=='b')
		PORTA = 0b0000001;

    }
}
int main(){
   //test_master();
   test_slave();


	return 0;
}

void i2c_init(){
	// set twi bit rate register
	TWBR = (unsigned char)TWBR_VALUE;
}

void i2c_start(){
    // sent start condition
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTA);
	// wait until the twint flag to set
    while(!(TWCR & (1<<TWINT)));
    // check that start condition transmitted
    while((TWSR & 0XF8)!= 0X08 );

}


void i2c_stop(){
    // sent stop condition
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO);

}

void i2c_write_addr(unsigned char addr){

	TWDR = addr;
	// set twint flag
	TWCR = (1<<TWEN)|(1<<TWINT);
	// wait until the twint flag to set
	while(!(TWCR & (1<<TWINT)));
	// check that address sent
	    while((TWSR & 0XF8)!= 0X18 );

}


void i2c_write_data(unsigned char data){

	TWDR = data;
	// set twint flag
	TWCR = (1<<TWEN)|(1<<TWINT);
	// wait until the twint flag to set
	while(!(TWCR & (1<<TWINT)));
	// check that  data written
	 while((TWSR & 0XF8)!= 0X28 );

}


void i2c_slave_init(unsigned char addr){
	TWAR = addr;
}


unsigned char  i2c_read_data(){
	 //  enable i2c  and  i2c ACK
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
     // wait until the twint flag to set
	    while(!(TWCR & (1<<TWINT)));
	 // check that data read
	   while((TWSR & 0XF8)!= 0X80 );

	   return TWDR ;

}


void i2c_ack(){
	while((TWSR &(0XF8))!=0X60){
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
		 while(!(TWCR & (1<<TWINT)));
	}
}
