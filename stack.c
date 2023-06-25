/********************************************************************************
* stack.c:
********************************************************************************/

/* Inkluderingsdirektiv: */
#include "stack.h"

static uint32_t stack[STACK_ADDRESS_WIDTH]; // storleken på stacken.
uint16_t sp = STACK_ADDRESS_WIDTH - 1;		  // stackpekaren pekar på det senast tillagda värdet.
bool stack_empty = true;						  // indikerar om stacken är tom.

/********************************************************************************
* reset_stack: sätter alla värden i stacken till noll och lägger stackpekaren
*					till toppen av stackminnet.
*
********************************************************************************/
void reset_stack(void)
{
	for (uint32_t i = 0; i < STACK_ADDRESS_WIDTH; i++)
	{
		stack[i] = 0x00;
	}
	sp = STACK_ADDRESS_WIDTH - 1;
	stack_empty = true;
	return;
}

/********************************************************************************
* push_stack: lägger till ett värde till botten av stacken. Om stacken är full returneras 1.
*
*             - value: 32-bit läggs på stacken.
********************************************************************************/
int push_stack(const uint32_t value)
{
	if (sp == 0)
	{
		return 1;
	}
	else
	{
		if (stack_empty)
		{
			stack[sp] = value;
			stack_empty = false;
		}
		else
		{
			stack[sp--] = value;
		}
		return 0;
	}
}

/********************************************************************************
* pop_stack: returnerar värdet lägnst upp på stacken och inkrementerar stakpekaren
*			 så att den pekar på nästa värde. om stackpekaren redan är vid botten så
*			 incrementeras ej stacken. Om stacken e tom returneras 0.
********************************************************************************/
uint32_t pop_stack(void)
{
	if (stack_empty)
	{
		return 0;
	}
	else
	{
		if (sp < STACK_ADDRESS_WIDTH - 1)
		{
			return stack[sp++];
		}	
		else
		{
			stack_empty = true;
			return stack[sp];
			sp = STACK_ADDRESS_WIDTH -1;
		}
	}
}