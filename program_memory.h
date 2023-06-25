#ifndef PROGRAM_MEMORY_HPP_
#define PROGRAM_MEMORY_HPP_

#include "header.h"

#define PROGRAM_MEMORY_DATA_SIZE 64 // 8 bitar op_code + 8 bitar op1 + 32 bitar op2.
#define PROGRAM_MEMORY_ADDRES_SIZE 255 // det här värdet kan ju vara större.

uint64_t program_memory[PROGRAM_MEMORY_DATA_SIZE];

uint64_t assemble(const uint8_t op_code, const uint8_t op1, const uint32_t op2);

uint64_t read_program_memory(const uint8_t address);

#endif /* PROGRAM_MEMORY_HPP_ */