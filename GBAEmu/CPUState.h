#pragma once
#include <cstdint>
#include "Registers.h"
#include "CPUMode.h"
#include "Instruction.h"

struct CPUState {
public:
	uint32_t current_opcode = 0;
	Registers reg;
	CPUModeType mode = CPUMODE_USER;
	Instruction current_instruction = Instruction("");

};