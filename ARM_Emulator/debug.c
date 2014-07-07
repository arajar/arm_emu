#include <stdio.h>

#include "cpu.h"

/**
* @brief prints the opcode type
* @param [in] opcode  The opcode
*/
void debug_print(uint8_t opcode)
{
	switch (opcode & 0xf)
	{
	case AND:
		printf("and");
		break;
	case EOR:
		printf("eor");
		break;
	case SUB:
		printf("sub");
		break;
	case RSB:
		printf("rsb");
		break;
	case ADD:
		printf("add");
		break;
	case ADC:
		printf("adc");
		break;
	case SBC:
		printf("sbc");
		break;
	case RSC:
		printf("rsc");
		break;
	case TST:
		printf("tst");
		break;
	case TEQ:
		printf("teq");
		break;
	case CMP:
		printf("cmp");
		break;
	case CMN:
		printf("cmn");
		break;
	case ORR:
		printf("orr");
		break;
	case MOV:
		printf("mov");
		break;
	case BIC:
		printf("bic");
		break;
	case MVN:
		printf("mvn");
		break;
	default:
		break;
	}
}
