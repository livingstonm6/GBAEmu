#pragma once
#include "Registers.h"
#include "CPUMode.h"
#include <memory>
#include "MemoryBus.h"
class CPU
{
private:
	Registers reg_;
	CPUModeType mode_ = CPUMODE_USER;

	MemoryBus* bus_ = nullptr;

	uint32_t current_opcode_;

	void fetch_instruction();
	void fetch_data();

	void print_status();

public:
	void connect(MemoryBus* bus);
	void step();
};

