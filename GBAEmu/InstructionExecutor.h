#pragma once
#include "CPUState.h"
#include "Registers.h"
class InstructionExecutor
{
private:
	// Performs branch instructions
	// B, BL, BX, BLX
	void branch(CPUState* state);

	bool check_condition(CPUState* state);

public:

	// Execute the current instruction on the given CPU state object.
	void execute(CPUState* state);
};

