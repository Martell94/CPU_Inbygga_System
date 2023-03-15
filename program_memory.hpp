#ifndef PROGRAM_MEMORY_H_
#define PROGRAM_MEMORY_H_

#define PROGRAM_MEMORY_DATA_SIZE 48 // 8 bitar op_code + 8 bitar op1 + 32 bitar op2.
#define PROGRAM_MEMORY_ADDRES_SIZE 255 // det här värdet kan ju vara störe.

/* Statiska funktioner: */

uint64_t assemble(const uint8_t op_code, const uint8_t op1, const uint32_t op2);


#endif PROGRAM_MEMORY_H_
