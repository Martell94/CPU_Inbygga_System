/************************************************************************************************
* program_memory.cpp: Innehåller programminnet, detta är programmet som köras av 64-bitars 
*                     systemet.
************************************************************************************************/
#include "program_memory.hpp"

uint64_t program_memory_write(const uint8_t operand, const uint8_t op1, const uint32_t op2)
{
   return (operand << 40)|(op1 << 32)|op2;
}

uint64_t read_program_memory(const uint8_t address)
{

}


