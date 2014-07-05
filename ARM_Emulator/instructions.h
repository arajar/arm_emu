#include <stdint.h>

struct Instruction
{
	union GenericInstruction // 32 bytes
	{
		uint8_t cond; // 4 bytes
		uint8_t flags; // 2 bytes
		uint8_t i; // 1 byte
		uint8_t opcode; // 4 bytes
		uint8_t s; // 1 byte
		uint16_t padding; // 20 bytes
	} generic_instruction;

	union MovInstruction // 32 bytes
	{
		uint8_t cond; // 4 bytes
		uint8_t flags; // 2 bytes
		uint8_t i; // 1 byte
		uint8_t opcode; // 4 bytes
		uint8_t s; // 1 byte
		uint8_t rn; // 4 bytes
		uint8_t rd; // 4 bytes
		uint8_t shifter; // 12 bytes
	} mov_instruction;
};