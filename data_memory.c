
 /********************************************************************************
* data_memory.c: 
********************************************************************************/

/* Inkluderingsdirektiv: */
#include "data_memory.h"

static uint32_t data_memory[DATA_MEMORY_ADDRESS_WIDTH];

/********************************************************************************
 *
 *  data_memory_reset: clearar data minnet
 * 
********************************************************************************/
void reset_data_memory(void)
{
	for (uint16_t i = 0; i < DATA_MEMORY_ADDRESS_WIDTH; i++)
	{
		data_memory[i] = 0x00;
	}
	return;
}

/********************************************************************************
 *
 *  write_data_memory: Skriver ett värde till en addres i dataminnet.
 *    
 *                   value: värdet som skall skrivas till minnesadressen.
 *                   address: addresen i dataminnet dit värdet skall skrivars. 
 * 
********************************************************************************/
int write_data_memory(const uint16_t address, const uint32_t value)
{
	if (address < DATA_MEMORY_ADDRESS_WIDTH)
	{
		data_memory[address] = value;
		return 0;
	}
	else
	{
		return 1;
	}
}

/********************************************************************************
 *
 *  read_data_memory: läser ett värde från en addres i dataminnet.
 *    
 *                 address: addresen i dataminnet där ett värde skall läsas. 
 * 
********************************************************************************/
uint32_t read_data_memory(const uint16_t address)
{
	if (address < DATA_MEMORY_ADDRESS_WIDTH)
	{
		return data_memory[address];
	}
	else
	{
		return 0x00;
	}
}