#pragma once
#include "CPU.h"
#include "Memory.h"
class Emulator
{
private:
	CPU cpu;
	MemoryBus bus;
	bool running = true;

public:
	const void run();

};

