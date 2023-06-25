/********************************************************************************
* alu.h: Funktionsdeklarationer för ALU som sköter processorns aritmetiska och 
*			logiska operationer.
********************************************************************************/
#ifndef ALU_H_
#define ALU_H_

/* Inkluderingsdirektiv: */
#include "cpu.h"
#include <math.h>

uint32_t alu(uint16_t op, uint32_t a, uint32_t b, uint32_t* sr);

#endif /* ALU_H_ */