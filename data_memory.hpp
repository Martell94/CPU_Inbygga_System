#ifndef DATA_MEMORY_H_
#define  DATA_MEMORY_H_

#include <stdint.h>

#define DATA_MEMORY_DATA_WIDTH  32   /* 32 bits per address. */
#define DATA_MEMORY_ADDRESS_WIDTH 5000 /*  addresses (0 - 5000). */

static uint32_t data_memory[DATA_MEMORY_ADDRESS_WIDTH];


/********************************************************************************
 *
 *  data_memory_reset: clearar data minnet
 * 
********************************************************************************/
void data_memory_reset(void);

/********************************************************************************
 *
 *  data_memory_write: Skriver ett värde till en addres i dataminnet.
 *    
 *                   data: värdet som skall skrivas till minnesadressen.
 *                   addres: addresen i dataminnet dit värdet skall skrivars. 
 * 
********************************************************************************/
void data_memory_write(const uint32_t data,const uint16_t addres);

/********************************************************************************
 *
 *  data_memory_read: läser ett värde från en addres i dataminnet.
 *    
 *                 addres: addresen i dataminnet där ett värde skall läsas. 
 * 
********************************************************************************/
uint32_t data_memory_read(const uint16_t addres);

#endif // _DATA_MEMORY_H_