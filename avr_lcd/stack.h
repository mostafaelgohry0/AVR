/*
 * stack.h
 *
 *  Created on: Oct 10, 2019
 *      Author: mostafa
 */

#ifndef STACK_H_
#define STACK_H_


#include <stdio.h>



void push(char x);
char pop ();
void intial_stack(int x);
int is_stack_empty();
int is_stack_full();
int stack_size();
void show_stack_elements();
int  top_stack_element();
int  insert_data();

void keypad();


#endif /* STACK_H_ */
