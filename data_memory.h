/********************************************************************************
* data_memory.h:
********************************************************************************/
#ifndef DATA_MEMORY_H_
#define DATA_MEMORY_H_

/* Inkluderingsdirektiv: */
#include "cpu.h"

#define DATA_MEMORY_ADDRESS_WIDTH 300

/* Funktionsdeklarationer: */

/********************************************************************************
 *
 *  data_memory_reset: clearar data minnet
 * 
********************************************************************************/
void reset_data_memory(void);

/********************************************************************************
 *
 *  write_data_memory: Skriver ett värde till en addres i dataminnet.
 *    
 *                   value: värdet som skall skrivas till minnesadressen.
 *                   address: addresen i dataminnet dit värdet skall skrivars. 
 * 
********************************************************************************/
int write_data_memory(const uint16_t address, const uint32_t value);

/********************************************************************************
 *
 *  read_data_memory: läser ett värde från en addres i dataminnet.
 *    
 *                 address: addresen i dataminnet där ett värde skall läsas. 
 * 
********************************************************************************/
uint32_t read_data_memory(const uint16_t address);

#endif /* DATA_MEMORY_H_ */