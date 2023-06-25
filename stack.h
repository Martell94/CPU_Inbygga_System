
/********************************************************************************
* stack.h: Inehåller definitioner och direktiv för användning av stacken.
********************************************************************************/
#ifndef STACK_H_
#define STACK_H_

/* Inkluderings direktiv: */
#include "cpu.h"

/* Macro definitioner: */
#define STACK_ADDRESS_WIDTH 255 /* stacken har plats för 255 olika addreser. */
#define STACK_DATA_WIDTH    32    /* 32 bitars per addres. */

/********************************************************************************
* stack_reset: Clears content of the stack and sets the stack pointer to the
*              top of the stack.
********************************************************************************/
void stack_reset(void);

/********************************************************************************
* stack_push: Pushes value to the bottom of the stack. If the stack is full,
*             the value isn't pushed and error code 1 is returned. Otherwise
*             return code 0 is returned after successful push and the stack
*             pointer is decremented.
* 
*             - value: 8-bit value to be pushed to the stack.
********************************************************************************/
int stack_push(const uint8_t value);

/********************************************************************************
* stack_pop: Returned value popped  from the stack and increments the stack 
*            pointer if it isn't already pointing to the top of the stack. 
*            If the stack is empty, the value 0x00 is returned.
********************************************************************************/
uint8_t stack_pop(void);

/********************************************************************************
* stack_pointer: Returns the address of the stack pointer.
********************************************************************************/
uint16_t stack_pointer(void);

/********************************************************************************
* stack_last_added_element: Returns the element last added to the stack. 
********************************************************************************/
uint8_t stack_last_added_element(void);
