
/********************************************************************************
* stack.h: 

********************************************************************************/
#ifndef STACK_H_
#define STACK_H_

/* Inkluderingsdirektiv: */
#include "cpu.h"

#define STACK_ADDRESS_WIDTH 100

/* Funktionsdeklarationer */
/********************************************************************************
* reset_stack: sätter alla värden i stacken till noll och lägger stackpekaren 
*					till toppen av stackminnet.
*
********************************************************************************/
void reset_stack(void);

/********************************************************************************
* push_stack: lägger till ett värde till botten av stacken. Om stacken är full returneras 1.
*
*             - value: 32-bit läggs på stacken.
********************************************************************************/
int push_stack(const uint32_t value);

/********************************************************************************
* pop_stack: returnerar värdet lägnst upp på stacken och inkrementerar stakpekaren
*			 så att den pekar på nästa värde. om stackpekaren redan är vid botten så
*			 incrementeras ej stacken. Om stacken e tom returneras 0.
********************************************************************************/
uint32_t pop_stack(void);

#endif /* STACK_H_ */
