/********************************************************************************
* control_unit.c: Funktionsdefinitioner för CPU:ns kontrollenhet som hämtar,
*						avkodar och utför instruktioner.
********************************************************************************/

/* Inkluderingsdirektiv: */
#include "control_unit.h"

/* Statiska variabler: */
static uint16_t pc;			// Programräknare
static uint32_t sr;			// Statusregister
static uint64_t ir;			// Instruktionsregister

static uint16_t OP_code;	// OP-kod
static uint16_t op1;			// Operand 1
static uint32_t op2;		   // Operand 2

static enum CPU_state current_state;
static volatile uint32_t pins_latest_value;
static uint32_t reg[CPU_REGISTER_ADDRESS_WIDTH];

/* Statiska funktioner: */
static void reset_io(void);
static void update_io(void);
static inline void clear_cpu_registers(void);
static inline void monitor_interrupts(void);
static inline void check_for_interrupt_requests(void);
static inline void generate_interrupt(const uint16_t interrupt_vector);
static inline void return_from_interrupt(void);


/********************************************************************************
* reset: Återställer kontrollenheten till utgångsläget där programräknaren, 
*			statusregistret och instruktionsregistret är 0. Läget sätts över till
*			'FETCH' så att kontrollenheten vet att den ska hämta nästa instruktion.
********************************************************************************/
void reset(void)
{
	pc = 0x00;
	sr = 0x00;
	ir = 0x00;
		
	OP_code = 0x00;
	op1		= 0x00;
	op2		= 0x00;
	
	current_state = FETCH;
	pins_latest_value = 0x00;
	
	reset_io();
	clear_cpu_registers();
	write_program_memory();
	reset_stack();
	reset_data_memory();
	return;
}

/********************************************************************************
* execute: Definition av vad CPU:n ska göra beroende på vilket tillstånd den
*			  hamnar i. Går igenom FETCH > DECODE > EXECUTE cykeln för att exekvera
*			  det som står skrivet i programminnet program_memory.c
********************************************************************************/
void execute(void)
{
	switch (current_state)
	{
		case FETCH:
		{
			ir = read_program_memory(pc++);
			current_state = DECODE;
			break;
		}
		case DECODE:
		{
			OP_code = (uint16_t)(ir >> 48);
			op1 = (uint16_t)(ir >> 32);
			op2 = (uint32_t)(ir);
			
			current_state = EXECUTE;
			break;
		}
		case EXECUTE:
		{
			switch(OP_code)
			{
				case NOP:
				{
					break;	
				}
				case LDI:
				{
					reg[op1] = op2;
					break;
				}
				case LD:
				{
					reg[op1] = read_data_memory(reg[op2]);
					break;
				}
				case IN:
				{
					reg[op1] = read_data_memory(op2);
					break;
				}
				case OUT:
				{
					if (op1 == PIN)
					{
						uint32_t port = read_data_memory(PIN) ^ reg[op2];
						write_data_memory(PORT, port);
					}
					else
					{
						write_data_memory(op1, reg[op2]);
					}
					break;
				}
				case OUTI:
				{
					if (op1 == PIN)
					{
						uint32_t port = read_data_memory(PORT) ^ op2;
						write_data_memory(PORT, port);
					}
					else
					{
						write_data_memory(op1, op2);
					}
					break;
				}
				case CLR:
				{
					reg[op1] = 0x00;
					break;
				}
				case OR:
				{
					reg[op1] = alu(OR, reg[op1], reg[op2], &sr);
					break;
				}
				case ORI: 
				{
					reg[op1] = alu(OR, reg[op1], op2, &sr);
					break;
				}
				case AND:
				{
					reg[op1] = alu(AND, reg[op1], reg[op2], &sr);
					break;
				}
				case ANDI:
				{
					reg[op1] = alu(AND, reg[op1], op2, &sr);
					break;
				}
				case XOR:
				{
					reg[op1] = alu(XOR, reg[op1], reg[op2], &sr);
					break;
				}
				case XORI:
				{
					reg[op1] = alu(XOR, reg[op1], op2, &sr);
					break;
				}
				case ADD:
				{
					reg[op1] = alu(ADD, reg[op1], reg[op2], &sr);
					break;
				}
				case ADDI:
				{
					reg[op1] = alu(ADD, reg[op1], op2, &sr);
					break;
				}
				case SUB:
				{
					reg[op1] = alu(SUB, reg[op1], reg[op2], &sr);
					break;
				}
				case SUBI:
				{
					reg[op1] = alu(SUB, reg[op1], op2, &sr);
					break;
				}
				case INC:
				{
					reg[op1] = alu(ADD, reg[op1], 1, &sr);
					break;
				}
				case DEC:
				{
					reg[op1] = alu(SUB, reg[op1], 1, &sr);
					break;
				}
				case COMP:
				{
					(void)(alu(SUB, reg[op1], reg[op2], &sr));
					break;
				}
				case COMPI:
				{
					(void)(alu(SUB, reg[op1], op2, &sr));
					break;
				}
				case JMP:
				{
					pc = op1;
					break;
				}
				case BREQ:
				{
					if(read(&sr, Z)) pc = op1;
					break;
				}
				case BRNE:
				{
					if(!read(&sr, Z)) pc = op1;
					break;
				}
				case BRGT:
				{
					if (!read(&sr, S) && !read(&sr, Z)) pc = op1;
					break;
				}
				case BRLE:
				{
					if (read(&sr, S) || read(&sr, Z)) pc = op1;
					break;
				}
				case BRLT:
				{
					if (read(&sr, S)) pc = op1;
					break;
				}
				case CALL:
				{
					push_stack(pc);
					pc = op1;
					break;
				}
				case RET:
				{
					pc = pop_stack();
					break;
				}
				case RETI:
				{
					return_from_interrupt();
					break;
				}
				case PUSH:
				{
					push_stack(reg[op1]);
					break;
				}
				case POP:
				{
					reg[op1] = pop_stack();
					break;
				}
				case LSL:
				{
					reg[op1] = reg[op1] << 1;
					break;
				}
				case LSR:
				{
					reg[op1] = reg[op1] >> 1;
					break;
				}
				case SEI:
				{
					set(&sr, I);
					break;
				}
				case CLI:
				{
					clr(&sr, I);
					break;
				}
				default:
				{
					reset();
					break;
				}
			}
			
			check_for_interrupt_requests();
			current_state = FETCH;
			break;
		}
		
		default:
		{
			reset();
			break;
		}
		
	}
	
	update_io();
	monitor_interrupts();
	return;
}


/* Statiska funktionsdefinitioner: */
static void reset_io(void)
{
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0x00;
	
	return;
}

static void update_io(void)
{
	const uint32_t port = read_data_memory(PORT);
	const uint32_t ddr  = read_data_memory(DDR);
	const uint32_t pin  = ((uint32_t)(((uint32_t)PINC) << 16) | (((uint32_t)PINB) << 8) | ((uint32_t)PIND));
	
	write_data_memory(PIN, pin);
	
	PORTB = (uint8_t)(port >> 8);
	PORTC = (uint8_t)(port >> 16);
	PORTD = (uint8_t)(port);
	
	DDRB = (uint8_t)(ddr >> 8);
	DDRC = (uint8_t)(ddr >> 16);
	DDRD = (uint8_t)(ddr);
	
	return;
}

static inline void clear_cpu_registers(void)
{
	for (uint8_t i = 0; i < CPU_REGISTER_ADDRESS_WIDTH; i++)
	{
		reg[i] = 0x00;
	}
	return;
}

static inline void monitor_interrupts(void)
{
	const uint32_t pin = read_data_memory(PIN);
	
	for (uint8_t i = 0; i < CPU_REGISTER_ADDRESS_WIDTH; i++)
	{
		if (read(&pin, i) != read(&pins_latest_value, i))
		{
			const uint32_t pcmsk = read_data_memory(PCMSK);
			
			if (read(&pcmsk, i))
			{
				uint32_t ifr = read_data_memory(IFR);
				set(&ifr, PCIF);
				write_data_memory(IFR, ifr);
				break;
			}
		}
	} 
	
	pins_latest_value = pin;
	return;
}

static inline void check_for_interrupt_requests(void)
{
	if (read(&sr, I))
	{
		uint32_t ifr       = read_data_memory(IFR);
		const uint32_t icr = read_data_memory(ICR);
		
		if (read(&ifr, PCIF) && read(&icr, PCIE))
		{
			clr(&ifr, PCIF);
			write_data_memory(IFR, ifr);
			generate_interrupt(PCI_vect);
		}
	}
	return;
}

static inline void generate_interrupt(const uint16_t interrupt_vector)
{
	push_stack(pc);
	pc = interrupt_vector;
	clr(&sr, I);
	return;
}

static inline void return_from_interrupt(void)
{
	pc = pop_stack();
	set(&sr, I);
	return;
}