#pragma once
#include "Registers.h"
#include "CPUState.h"
#include <memory>
#include "MemoryBus.h"
#include "InstructionExecutor.h"
#include "OpcodeDecoder.h"

class CPU
{
private:
	MemoryBus* bus_ = nullptr;

	CPUState state_;

	InstructionExecutor executor_;
	OpcodeDecoder decoder_;

	void fetch_instruction();
	void fetch_data();

	void print_status();

public:

	// Receives pointer to MemoryBus when called by Emulator.
	void connect(MemoryBus* bus);

	// Performs one CPU step
	void step();
};

