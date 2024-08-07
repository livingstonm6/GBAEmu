#pragma once
#include <cstdint>
#include "Registers.h"
#include "CPUMode.h"

struct CPUState {
public:
	uint32_t current_opcode = 0;
	Registers reg;
	CPUModeType mode = CPUMODE_USER;

};