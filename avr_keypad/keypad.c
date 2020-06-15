#include  "keypad.h"
#include "seven_segment.h"

static  uint8 out_char ;

int main(){

	// disable jtag  and use port c
	//MCUCSR = (1<<JTD);
	//MCUCSR = (1<<JTD);
    test_key();
	return 0;
}


/******************
 * test  function
 * function name  : test_key
 * input  : None
 * return : None
 *****************/
void  test_key(){

	while(1){
		Set_Seven(key_scan());
	}
}

/*********************************
*Service name:key_scan
*Service ID[hex] :
*Sync/Async: Synchronous
*Reentrancy: Reentrant
*Parameters (in):  None
*Parameters (inout):  None
*Parameters (out): None
*Return value: uint8  unsigned char with the pressed character
*Description:  function that check if a key pressed

****************************************/

//////////////////////////////////////////
                       ///  pins  connection
                       /// col4  --> pinx 0
                       /// col3  -->  pinx 1
                       /// col2  -->  pinx 2
                       /// col1  -->  pinx 3
                       /// row4-->  pinx 4
                       /// row3 -->  pinx 5
                      /// row2  -->  pinx 6
                      ///  row1 -->  pinx  7
  /// ////////////////////////////////////////

uint8  key_scan(){

	// configuration
	// set columns  as input from pin 0 to 3
	// set  rows  as output    from pin 4 to 7
	SET_PORT_VAL(key_ddr,0XF0);

	// set pull up resister
	SET_PORT_VAL(key_port,0xff);

    //  set  row 1 with low    and the check for  which   column to pull down
///////////////////////////////////////////////////////
//	key_port=0b01111111;
	CLEAR_BIT(key_port,row1);
      asm("NOP"); // this used to make the port take time to set its value before check on which column to pull down

// check  for column 1    result will be  1
	 if((GET_BIT(key_pin,col1))==0){
		 //Set_Seven('1') ;
	     //return '1';
		  out_char='1';
	 }

	 // check  for column 2    result will be  2
	 else if((GET_BIT(key_pin,col2))==0){
	    //Set_Seven('2');
	     //return '2';
		 out_char='2';
	 }

	 // check  for column 3    result will be  3
	 else if((GET_BIT(key_pin,col3))==0){
	     // Set_Seven('3');
	     // return '3';
		 out_char='3';
	 }

	 // check  for column 4    result will be  A
	 else if((GET_BIT(key_pin,col4))==0){
		  //Set_Seven('A');
	     //	 return 'A';
		 out_char='A';
	 }


	 SET_BIT(key_port,row1);
///////////////////////////////////////////////////////


	 //  set  row 2 with low    and the check for  which   column to pull down
///////////////////////////////////////////////////////
	// key_port=0b10111111;
	CLEAR_BIT(key_port,row2);
	 asm("NOP");

	 // check  for column 1    result will be  4
	 if((GET_BIT(key_pin,col1))==0){
            //Set_Seven('4');
		 out_char ='4';
	 }

	 // check  for column 2    result will be  5
	 else if ((GET_BIT(key_pin,col2))==0){
        //Set_Seven('5');
		 out_char='5';
	 }

	 // check  for column 3    result will be  6
	 else if((GET_BIT(key_pin,col3))==0){
       //  Set_Seven('6');
		 out_char= '6';
	 }

	 // check  for column 4   result will be  B
	 else if((GET_BIT(key_pin,col4))==0){
        //Set_Seven('B');
		 out_char= 'B';
	 }
	 SET_BIT(key_port,row2);
///////////////////////////////////////////////////////////////////


	 //  set  row 3 with low    and the check for  which   column to pull down
///////////////////////////////////////////////////////
    //key_port=0b11011111;
	CLEAR_BIT(key_port,row3);
    asm("NOP");

    // check  for column 1   result will be  7
    if((GET_BIT(key_pin,col1))==0){
	   //  Set_Seven('7');
		 out_char= '7';
	 }

	 // check  for column 2    result will be  8
    else if((GET_BIT(key_pin,col2))==0){
         //Set_Seven('8');
    	 out_char='8';
     }

	 // check  for column 3    result will be  9
    else if((GET_BIT(key_pin,col3))==0){
    	  //   Set_Seven('9');
    	  out_char= '9';
      }

	 // check  for column 4    result will be  C
    else if((GET_BIT(key_pin,col4))==0){
		//  Set_Seven('C');
		  out_char= 'C';
	  }
	 SET_BIT(key_port,row3);
	///////////////////////////////////////////////////////




	 //  set  row 4 with low    and the check for  which   column to pull down
	///////////////////////////////////////////////////////
	// key_port=0b11101111;
	CLEAR_BIT(key_port,row4);
	 asm("NOP");

	 // check  for column 1    result will be  #          // NOT IMPLEMET  NOW
 if((GET_BIT(key_pin,col1))==0){
	    //  Set_Seven('A');
	    //return 0b00000001 ;
	 }

	 // check  for column 2    result will be  0
 else if((GET_BIT(key_pin,col2))==0){
	     //Set_Seven('0');
		 out_char= '0';
	 }

	 // check  for column 3    result will be  *       // NOT IMPLEMET  NOW
 else if((GET_BIT(key_pin,col3))==0){
          //     Set_Seven('C');
	     //return 0b00000100;
     }

	 // check  for column 4    result will be  D
 else if((GET_BIT(key_pin,col4))==0){
	   //    Set_Seven('D');
		 out_char= 'D';
	 }
	 SET_BIT(key_port,row4);
	 ///////////////////////////////////////////////////////

	 return out_char;

}
