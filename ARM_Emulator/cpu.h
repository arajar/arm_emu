#include <stdint.h>

enum Registers
{
	R0, R1, R2, R3, // Argument registers
	R4, R5, R6, R7, R8, R9, // Variable registers
	R10, // SL, stack limit
	R11, // FP, frame pointer
	R12, // IP, procedure entry temporary workspace
	R13, // SP, stack pointer
	R14, // LR, link register
	R15, // PC, program counter
	SL = R10,
	FP = R11,
	IP = R12,
	SP = R13,
	LR = R14,
	PC = R15,
};

enum OpCodes
{
	AND = 0x0,
	EOR = 0x1,
	SUB = 0x2,
	RSB = 0x3,
	ADD = 0x4,
	ADC = 0x5,
	SBC = 0x6,
	RSC = 0x7,
	TST = 0x8,
	TEQ = 0x9,
	CMP = 0xA,
	CMN = 0xB,
	ORR = 0xC,
	MOV = 0xD,
	BIC = 0xE,
	MVN = 0xF,
};

typedef struct // 32 bytes
{
	uint8_t cond; // 4 bytes
	uint8_t flags; // 2 bytes
	uint8_t i; // 1 byte
	uint8_t opcode; // 4 bytes
	uint8_t s; // 1 byte
	uint8_t rn; // 4 bytes
	uint8_t rd; // 4 bytes
	uint8_t shifter; // 12 bytes
} Instruction;

typedef struct
{
	uint8_t num_regs;
	uint32_t registers[16];
	uint32_t cpsr;
	uint32_t fetched_instruction;
	Instruction decoded_instruction;
	uint8_t fetched;
	uint8_t decoded;
	uint8_t* memory;
	uint32_t memsize;
	uint8_t* binary_data;
	uint8_t binsize;
} ArmCPU;

int InitCPU(ArmCPU* cpu, char* file);
void Step(ArmCPU* cpu);

void Fetch(ArmCPU* cpu);