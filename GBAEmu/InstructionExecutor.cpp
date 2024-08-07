#include "InstructionExecutor.h"
#include <iostream>
#include <bitset>
void InstructionExecutor::branch(CPUState* state)
{
	uint32_t pc = state->reg.read(REG_PC, state->mode);

	// first 23 bits are offset magnitude, 24th is sign
	int offset = state->current_opcode & 0x7FFFFF; 
	if ((state->current_opcode >> 23) & 1) {
		offset *= -1;
	}

	if (state->current_opcode >> 28 == 0b1111) {
		// BLX immediate
		std::cout << "BLX Instruction unsupported" << std::endl;
		exit(-2);
	}

	if ((state->current_opcode >> 24) & 1) {
		//BL - call to subroutine (push pc before jump)
		state->reg.write(REG_LR, pc + 4, state->mode);
		
	}

	// B - jump to subroutine
	uint32_t new_value = pc + 8 + (offset * 4);

	state->reg.write(REG_PC, new_value, state->mode);

	return;

}


void InstructionExecutor::execute(CPUState* state)
{
	uint8_t op_bits = (state->current_opcode >> 25) & 0b111;

	if (op_bits == 0b101) {
		branch(state);
		return;
	}

	std::cerr << "Error: unsupported opcode" << std::endl;

	exit(-3);

}
