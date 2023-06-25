
/********************************************************************************
* cpu.h: 
********************************************************************************/
#ifndef CPU_H_
#define CPU_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

#define CPU_REGISTER_ADDRESS_WIDTH 32

#define NOP   0x00         // No operation.
#define LDI   0x01         // Laddar ett värde från ett CPU-register.
#define LD    0x02         // Kopierar innehåll från ett CPU-register till ett annat.
#define IN    0x03         // Läser in ett värde från ett IO register.
#define OUT   0x04         // Skriver innehållet från ett CPU register till IO-port.
#define OUTI  0x05         // Skriver en konstant till dataminnet.
#define CLR   0x06         // Frigör ett CPU register.
#define ORI   0x07         // OR-operation med en konstant.
#define OR    0x08         // OR-operation med ett CPU-register.
#define ANDI  0x09         // AND-operation med en konstant.
#define AND   0x0A         // AND-operation med ett CPU-register.
#define XORI  0x0B         // XOR-operation med en konstant.
#define XOR   0x0C         // XOR operation med ett CPU-register.
#define ADDI  0x0D         // Addition med en konstant.
#define ADD   0x0E         // Addition med ett CPU-register.
#define SUBI  0x0F         // Subtraktion med en konstant.
#define SUB   0x10         // Utför en subtraktion med ett CPU-register.

#define INC   0x11         // Inkrementerer värdet i ett CPU-register.
#define DEC   0x12         // Dekrementerar värdet i ett CPU-register.
#define COMPI 0x13         // Jamnför värdet i ett CPU-register med en konstant.
#define COMP  0x14         // Jamnför värdet i ett CPU-register med ett annat CPU-register.
#define JMP   0x15         // Hoppar till specificerad adress.
#define BREQ  0x16         // Hoppar till specificerad adress om resultatet från jämförelsen är 0.
#define BRNE  0x17         // Hoppar till specificerad adress om resultatet från jämförelsen inte är 0.
#define BRGT  0x18         // Hoppar till specificerad adress om resultatet från jämförelsen är större än 0.
#define BRLE  0x19         // Hoppar till specificerad adress om resultatet från jämförelsen är mindre än eller lika med 0.
#define BRLT  0x1A         // Hoppar till specificerad adress om resultatet från jämförelsen är mindre än 0.

#define CALL  0x1B         // Hoppar till specificerad subrutin och sparar återhoppsadressen på stacken.
#define RET   0x1C         // Returnerar från en subrutin genom att hämta återhoppsadressen från stacken.
#define RETI  0x1D         // Returnerar från en avbrottsrutin genom att återställa programmet till tidigare stadie.

#define PUSH  0x1E         // Pushar ett värde från CPU-register till stacken.
#define POP   0x1F         // Poppar ett värde från stacken och sparar det i ett CPU-register.
#define LSL   0x20         // Skiftar ett värde i ett CPU-register en gång åt vänster.
#define LSR   0x21         // Skifter ett värde i ett CPU-register en gång åt höger.
#define SEI   0x22         // Aktiverar globala avbrott.
#define CLI   0x23         // Inaktiverar globala avbrott.

#define I 5                // Avbrotts-flagga.
#define S 4                // Signerad-flagga.
#define N 3                // Negativ-flagga.
#define Z 2                // Noll-flagga.
#define V 1                // Overflow-flagga.
#define C 0                // Carry-flagga.

#define RESET_vect  0x00   // Resetvektor.
#define PCI_vect    0x02   // PCI vektor för PORT A.

#define DDR         0x00   // Datariktningsregister för PORT A.
#define PORT        0x01   // Dataregister för PORT A.
#define PIN         0x02   // PIN Register för PORT A.
#define ICR         0x03   // Register för avbrottskontroll
#define IFR         0x04   // Register för avbrottsflaggor.
#define PCMSK       0x05   // Register för avbrott på PINs.

#define PCIE 0
#define PCIF 0

#define PORT0  0 
#define PORT1  1 
#define PORT2  2 
#define PORT3  3 
#define PORT4  4 
#define PORT5  5 
#define PORT6  6 
#define PORT7  7 
#define PORT8  8 
#define PORT9  9 
#define PORT10 10
#define PORT11 11
#define PORT12 12
#define PORT13 13

#define R0  0x00
#define R1  0x01
#define R2  0x02
#define R3  0x03
#define R4  0x04
#define R5  0x05
#define R6  0x06
#define R7  0x07
#define R8  0x08
#define R9  0x09
#define R10 0x0A
#define R11 0x0B
#define R12 0x0C
#define R13 0x0D
#define R14 0x0E
#define R15 0x0F
#define R16 0x10
#define R17 0x11
#define R18 0x12
#define R19 0x13
#define R20 0x14
#define R21 0x15
#define R22 0x16
#define R23 0x17
#define R24 0x18
#define R25 0x19

/********************************************************************************
* set: Ettställer en bit i ett register där 'reg' avser registret och 'bit' 
*		 avser vilken bit. 
********************************************************************************/
static inline void set(volatile uint32_t* reg, const uint8_t bit)
{
	*reg |= (1ULL << bit);
	return;
}

/********************************************************************************
* clr: Nollställer en bit i ett register där 'reg' avser registret och 'bit'
*		 avser vilken bit.
********************************************************************************/
static inline void clr(volatile uint32_t* reg, const uint8_t bit)
{
	*reg &= !(1ULL << bit);
	return;
}

/********************************************************************************
* read: Läser en bit i ett register där 'reg' avser registret och 'bit'
*		  avser vilken bit.
********************************************************************************/
static inline bool read(const volatile uint32_t* reg, const uint8_t bit)
{
	return *reg & (1UL << bit);
}

/********************************************************************************
* read64: Läser en bit i ett 64-bitars register där 'reg' avser registret och 
*			 'bit' avser vilken bit.
********************************************************************************/
static inline bool read64(const volatile uint64_t* reg, const uint8_t bit)
{
	return *reg & (1UL << bit);
}

/* Enumeration av CPU:ns state: */
enum CPU_state
{
	FETCH,
	DECODE,
	EXECUTE
};

#endif /* CPU_H_ */