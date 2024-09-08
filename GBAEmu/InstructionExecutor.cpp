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

bool InstructionExecutor::check_condition(CPUState* state)
{
	int cond = state->current_opcode >> 28;
	switch (cond) {
	case 0b0000:
		return state->reg.get_flag(FLAG_Z);
	case 0b0001:
		return !state->reg.get_flag(FLAG_Z);
	case 0b0010:
		return state->reg.get_flag(FLAG_C);
	case 0b0011:
		return !state->reg.get_flag(FLAG_C);
	case 0b0100:
		return state->reg.get_flag(FLAG_N);
	case 0b0101:
		return !state->reg.get_flag(FLAG_N);
	case 0b0110:
		return state->reg.get_flag(FLAG_V);
	case 0b0111:
		return !state->reg.get_flag(FLAG_V);
	case 0b1000: {
		bool c = state->reg.get_flag(FLAG_C);
		bool z = state->reg.get_flag(FLAG_Z);
		return (c == true && z == false);
	}
	case 0b1001: {
		bool c = state->reg.get_flag(FLAG_C);
		bool z = state->reg.get_flag(FLAG_Z);
		return (c == 0 || z == 1);
	}
	case 0b1010: {
		bool n = state->reg.get_flag(FLAG_N);
		bool v = state->reg.get_flag(FLAG_V);
		return (n == v);
	}
	case 0b1011: {
		bool n = state->reg.get_flag(FLAG_N);
		bool v = state->reg.get_flag(FLAG_V);
		return (n != v);
	}
	case 0b1100: {
		bool z = state->reg.get_flag(FLAG_Z);
		bool n = state->reg.get_flag(FLAG_N);
		bool v = state->reg.get_flag(FLAG_V);
		return (z == 0 && n == v);
	}
	case 0b1101: {
		bool z = state->reg.get_flag(FLAG_Z);
		bool n = state->reg.get_flag(FLAG_N);
		bool v = state->reg.get_flag(FLAG_V);
		return (z == 1 || n != v);
	}
	case 0b1110:
		return true;
	}
}


void InstructionExecutor::execute(CPUState* state)
{
	bool cond = check_condition(state);
	std::cout << "Condition: " << cond << "\n";
	if (!cond) {
		return;
	}

	uint8_t op_bits = (state->current_opcode >> 25) & 0b111;

	if (op_bits == 0b101) {
		branch(state);
		return;
	}

	std::cerr << "Error: unsupported opcode" << std::endl;

	exit(-3);

}
