/********************************************************************************
* program_memory.h: 
********************************************************************************/
#ifndef PROGRAM_MEMORY_H_
#define PROGRAM_MEMORY_H_

/* Inkluderingsdirektiv: */
#include "cpu.h"

#define PROGRAM_MEMORY_ADDRESS_WIDTH 25

void write_program_memory(void);
uint64_t read_program_memory(const uint16_t address);

#endif /* PROGRAM_MEMORY_H_ */