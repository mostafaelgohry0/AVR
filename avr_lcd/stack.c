/*
 * stack.c
 *
 *  Created on: Oct 3, 2019
 *      Author: mostafa
 */
#include "stack.h"
	char *top;
	int max_size ;
	char *stack_arr;


void intial_stack(int x){

	stack_arr=  (char*) malloc(x*sizeof(char));
	top=stack_arr;   // assign the first address of array to  top
    max_size = x;
}

void push(char x){

	if(is_stack_full()==1){
		//	printf(" stack full\n");

		}
	else {
    *stack_arr = x;
   // printf("%d\n",*stack_arr);
     stack_arr++;
	}

}

char  pop(){
	// check if the stack empty
	if(is_stack_empty()==1){
	//	printf(" stack empty \n");
	      exit(0);
	}
	else {

	stack_arr--;
	return  *stack_arr;
	}
}



int  top_stack_element(){
	// check if the stack empty
	if(is_stack_empty()==1){
		//printf(" stack empty \n");
	      exit(0);
	}
	else {


	return  *--stack_arr;
	}
}





int  is_stack_empty(){
	if(stack_size()==0)
		return 1;
	else return 0;

}

int  is_stack_full(){
	if(stack_size()==max_size)
		return 1;
	else return 0;

}

int stack_size(){
	 int size;
	 size = (stack_arr - top);

   return size ;
}

void show_stack_elements(){
int i;;
/*

    printf(" [ ");
		for (i=0;i<stack_size();i++){
			   printf("%d\n",*(stack_arr-i-1) );
		}

		   printf(" ] \n");

*/
}
