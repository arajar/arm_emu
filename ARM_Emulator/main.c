
#include <stdio.h>
#include "debug.h"
#include "cpu.h"

/**
* @brief emulates ARM-v4 programs containing only MOV instructions in User32 mode
* @param [in,out] registers  Array containing r0 to r15 followed by cpsr
* @param [in] memory  Array containing 32-bit addressable program memory
* @return less than 0 if unsupported instructions found
*/
int ARM_User32_MOV_Emulator(unsigned int* registers, unsigned int* memory)
{

	return 0;
}

int main(int argc, char** argv)
{
	//ARM_User32_MOV_Emulator(reg, memory);
	ArmCPU cpu;
	InitCPU(&cpu, "test.bi");

	while (cpu.registers[PC] < cpu.binsize + 8)
	{
		Step(&cpu);
	}


	return 0;
}
