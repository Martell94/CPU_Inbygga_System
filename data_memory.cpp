
 #include "data_memory.hpp" 



/********************************************************************************
 *
 *  data_memory_reset: clearar data minnet
 * 
********************************************************************************/
void data_memory_reset(void)
{
   for (uint16_t i = 0; i < DATA_MEMORY_DATA_WIDTH; i++)
   {
      data_memory[i] = 0x00;
   }
   return;
}

/********************************************************************************
 *
 *  data_memory_write: Skriver ett värde till en addres i dataminnet.
 *    
 *                   data: värdet som skall skrivas till minnesadressen.
 *                   addres: addresen i dataminnet dit värdet skall skrivars. 
 * 
********************************************************************************/
void data_memory_write(const uint32_t data,const uint16_t addres)
{
   if (addres <= DATA_MEMORY_DATA_WIDTH) return;
   data_memory[addres] = data;
   return;
}

/********************************************************************************
 *
 *  data_memory_read: läser ett värde från en addres i dataminnet.
 *    
 *                 addres: addresen i dataminnet där ett värde skall läsas. 
 * 
********************************************************************************/
uint32_t data_memory_read(const uint16_t addres)
{
   if (addres <= DATA_MEMORY_DATA_WIDTH) return 0;
   return data_memory[addres];
}