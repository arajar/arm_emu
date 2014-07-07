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
	cpu->binary_data = 0;
	cpu->cpsr = 0;
	cpu->fetched_instruction = 0;
	cpu->memsize = 0;
	cpu->binsize = 0;

	fp = fopen(file, "r");
	if (fp == 0)
	{
		printf("> Error opening file %s", file);
		return -1;
	}

	// Get the binary size
	fseek(fp, 0, SEEK_END);
	cpu->binsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// Reserve memory
	cpu->binary_data = (uint8_t*)malloc(cpu->binsize + 1);

	// Copy the data from the file to the cpu
	fgets((char*)cpu->binary_data, cpu->binsize + 1, fp);
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

	}

	if (cpu->registers[PC] < cpu->binsize)
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
	if (cpu->registers[PC] <= cpu->binsize - 4)
	{
		cpu->fetched_instruction += cpu->binary_data[PC];
		cpu->fetched_instruction += cpu->binary_data[PC + 1] << 8;
		cpu->fetched_instruction += cpu->binary_data[PC + 2] << 16;
		cpu->fetched_instruction += cpu->binary_data[PC + 3] << 24;

		cpu->fetched = 1;
	}
}