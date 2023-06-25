
/********************************************************************************
* control_unit.h: Funktionsdeklarationer för CPU:ns kontrollenhet som hämtar,
*						avkodar och utför instruktioner.
********************************************************************************/
#ifndef CONTROL_UNIT_H_
#define CONTROL_UNIT_H_

/* Inkluderingsdirektiv: */
#include "cpu.h"
#include "alu.h"
#include "data_memory.h"
#include "program_memory.h"
#include "stack.h"

/* Funktionsdeklarationer: */
void execute(void);

void reset(void);

#endif /* CONTROL_UNIT_H_ */