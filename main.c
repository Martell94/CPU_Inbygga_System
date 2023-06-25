/********************************************************************************
* main.c: Kör ett program som implementerar ett 32-bitars system för ATmega328P.
*			 I programmet togglas en lysdiod vid nedtryckning av knapp.
********************************************************************************/ 

/* Inkluderingsdirektiv: */
#include "control_unit.h"

/********************************************************************************
* main: Resettar systemet och startar sedan CPUn genom att köra funktionen
*		  execute som läser av programminnet och utför angivna instruktioner.
********************************************************************************/
int main(void)
{
	reset();
    while (1) 
    {
		 execute();
    }
}