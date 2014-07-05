
#include <stdio.h>
#include "instructions.h"

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

/**
* @brief emulates ARM-v4 programs containing only MOV instructions in User32 mode
* @param [in,out] registers  Array containing r0 to r15 followed by cpsr
* @param [in] memory  Array containing 32-bit addressable program memory
* @return less than 0 if unsupported instructions found
*/
int ARM_User32_MOV_Emulator(unsigned int* registers, unsigned int* memory)
{
	Instruction inst = *(Instruction*)(memory[registers[Registers::PC]]);
	if (inst.generic_instruction.opcode == OpCodes::MOV)
	{

	}

	return 0;
}

int main(int argc, char** argv)
{
	ARM_User32_MOV_Emulator(0, 0);

	return 0;
}
