/*
 * seven_segment.c
 *
 *  Created on: Jun 14, 2020
 *      Author: mostafa elgohary
 */

#include "seven_segment.h"

/***********************************************
*Service name:Set_Seven
*Service ID[hex] :
*Sync/Async: Synchronous
*Reentrancy: Reentrant
*Parameters (in): uint8  x    (unsigned char)  the value that will display on 7 segment
*Parameters (inout):  None
*Parameters (out): None
*Return value:  None
*Description:  set the 7 segment   display value
                           *  the range of display   numbers from 0 to 9   and characters   A ,B,C,D
                            * the input is char  like   Set_Seven('1')
                            //////////////////////////////////////////
	                        ///  pins  connection
	                        /// a   --> pinx 0
	                        /// b  -->  pinx 1
	                        /// c   -->  pinx 2
	                        /// d  -->  pinx 3
	                        /// e  -->  pinx 4
	                        /// f   -->  pinx 5
	                       /// g  -->  pinx 6
	                       /// .   -->  pinx  7
	                      /// ////////////////////////////////////////
********************************************************/

void set_seven( uint8 x){
	//number 0
	if(x=='0'){
		SEVEN_PORT = 0b10111111;
	}

		// number 1
	else if (x=='1') {
		SEVEN_PORT = 0b10000110;
	}

	    //  number 2
	else if(x=='2'){
		SEVEN_PORT = 0b11011011;
	}

	    // number 3
	else if(x=='3'){
		SEVEN_PORT = 0b11001111;
	}

	     // number 4
	else if(x=='4'){
		SEVEN_PORT = 0b11100110;
	}

		// number 5
	else if(x=='5'){
		SEVEN_PORT = 0b11101101;
	}

	    //number 6
	else if(x=='6'){
		SEVEN_PORT = 0b11111101;
	}

	    //number 7
	else if(x=='7'){
		SEVEN_PORT = 0b10000111;
	}

	       //number 8
	else if(x=='8'){
		SEVEN_PORT = 0b11111111;
	}

	    // number 9
	else if(x=='9'){
		SEVEN_PORT = 0b11101111;
	}

		// dot
	else if(x== '.'){
		SEVEN_PORT = 0b10000000;
	}

	else if(x=='A' ){
		SEVEN_PORT = 0b11110111;
	}

	else if(x== 'B'){
		SEVEN_PORT = 0b11111111;
	}

	else if(x== 'C'){
		SEVEN_PORT = 0b10111001;
	}

	else if(x== 'D'){
		SEVEN_PORT = 0b10111111;
	}

	else{
		SEVEN_PORT = 0b10000000;
	}

}


