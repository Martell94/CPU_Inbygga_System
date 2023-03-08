
#ifndef CPU_H_
#define CPU_H_

/* Include directives: */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*definering av Operationer*/
#define NOP    0x00
#define LOAD   0x01
#define WRITE  0x02
#define CLR    0x03
#define OR     0x04
#define XOR    0x05
#define AND    0x06
#define ADD    0x07
#define SUB    0x08
#define INC    0x09
#define DEC    0x0A
#define COMP   0x0B
#define JMP    0x0C
#define BREQ   0x0D
#define BRNE   0x0E
#define BRGE   0x0F
#define BRGT   0x10
#define BRLE   0x11
#define BRLT   0x12
#define CALL   0x13
#define RET    0x14
#define PUSH   0x15
#define POP    0x16
#define SHIFTL 0x17
#define SHIFTR 0x18
#define SEI    0x19
#define CLI    0x1A

/*definering av addreser PORT*/
#define GPIO0 0
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO8 8
#define GPIO9 9
#define GPIO10 10
#define GPIO11 11
#define GPIO12 12
#define GPIO13 13
#define GPIO14 14
#define GPIO15 15
#define GPIO16 16
#define GPIO17 17
#define GPIO18 18
#define GPIO19 19


#define R0  0x00 /* Address for CPU register R0. */
#define R1  0x01 /* Address for CPU register R1. */
#define R2  0x02 /* Address for CPU register R2. */
#define R3  0x03 /* Address for CPU register R3. */
#define R4  0x04 /* Address for CPU register R4. */
#define R5  0x05 /* Address for CPU register R5. */
#define R6  0x06 /* Address for CPU register R6. */
#define R7  0x07 /* Address for CPU register R7. */
#define R8  0x08 /* Address for CPU register R8. */
#define R9  0x09 /* Address for CPU register R9. */
#define R10 0x0A /* Address for CPU register R10. */
#define R11 0x0B /* Address for CPU register R11. */
#define R12 0x0C /* Address for CPU register R12. */
#define R13 0x0D /* Address for CPU register R13. */
#define R14 0x0E /* Address for CPU register R14. */
#define R15 0x0F /* Address for CPU register R15. */

#define R16 0x10 /* Address for CPU register R16. */
#define R17 0x11 /* Address for CPU register R17. */
#define R18 0x12 /* Address for CPU register R18. */
#define R19 0x13 /* Address for CPU register R19. */
#define R20 0x14 /* Address for CPU register R20. */
#define R21 0x15 /* Address for CPU register R21. */
#define R22 0x16 /* Address for CPU register R22. */
#define R23 0x17 /* Address for CPU register R23. */
#define R24 0x18 /* Address for CPU register R24. */
#define R25 0x19 /* Address for CPU register R25. */
#define R26 0x1A /* Address for CPU register R26. */
#define R27 0x1B /* Address for CPU register R27. */
#define R28 0x1C /* Address for CPU register R28. */
#define R29 0x1D /* Address for CPU register R29. */
#define R30 0x1E /* Address for CPU register R30. */
#define R31 0x1F /* Address for CPU register R31. */

#endif 