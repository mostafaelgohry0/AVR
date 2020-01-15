

 #include "spi.h"

unsigned char spi_tranceiver (unsigned char data);

int main(){

  // DDRD &=~(1<<PD7) ;
  // DDRD &=~(1<<PD6) ;
  DDRA |=(1<<PA0);
   //spi_master_init();
    spi_slave_init();
  unsigned char d;

	while(1){


	//d=	spi_tranceiver('a');
		// the master
/*
		if(PIND&=(1<<PD7) ){

			spi_master_transmit('A');
			PORTA ^=(1<<PA0);

		}
*/






		// the slave
		d = spi_slave_receive();


        if(d=='A'){
        					PORTA ^=(1<<PA0);

        		}

    	_delay_ms(200);





	}


	return 0;
}




unsigned char spi_tranceiver (unsigned char data)
{
    // Load data into the buffer
    SPDR = data;

    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF) ));

    // Return received data
    return(SPDR);
}

void spi_master_init(){

	// set MOSI and SCK as output
	DDR_SPI = (1<<MOSI)|(1<<SCK)|(1<<SS);
	DDR_SPI &=~(1<<MISO);
	//enable SPI ,master    set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);


}

void spi_slave_init(){


	// set MISO  as output
		DDR_SPI |= (1<<MISO);
		DDR_SPI &= ~(1<<MOSI)&~(1<<SCK)&~(1<<SS);
		//enable SPI
		SPCR = (1<<SPE);

}

void spi_master_transmit(unsigned char data){

	// set the data that you want to sent
	SPDR = data;
	// wait until the transmission complete
	while(!(SPSR&(1<<SPIF)));


}


unsigned char spi_slave_receive(){


		// wait until the reception complete
		while(!(SPSR&(1<<SPIF)));


		return (SPDR);

}

