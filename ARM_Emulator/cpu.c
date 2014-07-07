#include <stdio.h>
#include "cpu.h"

int InitCPU(ArmCPU* cpu, char* file)
{
	FILE* fp = 0;

	// Initialize the cpu
	cpu->num_regs = 16;
	for (int i = 0; i < cpu->num_regs; i++)
	{
		cpu->registers[i] = 0;
	}

	cpu->fetched = 0;
	cpu->decoded = 0;
	cpu->memory = 0;
	cpu->memory = 0;
	cpu->cpsr = 0;
	cpu->fetched_instruction = 0;
	cpu->mem_size = 0;

	fp = fopen(file, "r");
	if (fp == 0)
	{
		printf("> Error opening file %s", file);
		return -1;
	}

	// Get the binary size
	fseek(fp, 0, SEEK_END);
	cpu->mem_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// Reserve memory
	cpu->memory = (uint8_t*)malloc(cpu->mem_size + 1);

	// Copy the data from the file to the cpu
	fgets((char*)cpu->memory, cpu->mem_size + 1, fp);
	fclose(fp);
	fp = 0;

	return 0;
}

void Step(ArmCPU* cpu)
{
	if (cpu->decoded)
	{

	}

	if (cpu->fetched)
	{
		Decode(cpu);
		printf("mov R%i, %u\n", cpu->decoded_instruction.rd, cpu->decoded_instruction.shifter);
	}

	if (cpu->registers[PC] < cpu->mem_size)
	{
		Fetch(cpu);
	}
	else
	{
		cpu->fetched = 0;
	}

	cpu->registers[PC] += 4;
}

void Fetch(ArmCPU* cpu)
{
	cpu->fetched_instruction = 0;
	// Check if we can fetch a new instruction
	if (cpu->registers[PC] <= cpu->mem_size - 4)
	{
		cpu->fetched_instruction += cpu->memory[cpu->registers[PC]];
		cpu->fetched_instruction += cpu->memory[cpu->registers[PC] + 1] << 8;
		cpu->fetched_instruction += cpu->memory[cpu->registers[PC] + 2] << 16;
		cpu->fetched_instruction += cpu->memory[cpu->registers[PC] + 3] << 24;

		cpu->fetched = 1;
	}
}

void Decode(ArmCPU* cpu)
{
	uint8_t cond = cpu->fetched_instruction >> 28;
	cpu->decoded_instruction.cond = cond;

	cpu->decoded_instruction.opcode = get_bits(cpu->fetched_instruction, 21, 4);
	cpu->decoded_instruction.s = get_bits(cpu->fetched_instruction, 20, 1);
	cpu->decoded_instruction.rn = get_bits(cpu->fetched_instruction, 16, 4);
	cpu->decoded_instruction.rd = get_bits(cpu->fetched_instruction, 12, 4);
	cpu->decoded_instruction.shifter = get_bits(cpu->fetched_instruction, 0, 12);

	cpu->decoded = 1;
}

void Execute(ArmCPU* cpu)
{
	/*cpu->registers[cpu->decoded_instruction.rd] = shifter.operand;
	if (shifter.carry_out)
	{
		cpu->cpsr |= 1 << 29;
	}
	else
	{
		cpu->cpsr &= ~(1 << 29);
	}*/
}


uint32_t get_bits(uint32_t number, uint8_t start, uint8_t length)
{
	return (number >> start) % (1 << length);
}