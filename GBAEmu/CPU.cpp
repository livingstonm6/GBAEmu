#include "CPU.h"
#include <iostream>
#include <bitset>

void CPU::fetch_instruction()
{
	uint32_t address = reg_.read(REG_PC, mode_);
	current_opcode_ = bus_->read32(address);
	std::cout << "Opcode: " << std::bitset<32>(current_opcode_) << std::endl;

}

void CPU::fetch_data()
{
}

void CPU::print_status()
{
}

void CPU::connect(MemoryBus* bus)
{
	bus_ = bus;
}

void CPU::step()
{
	fetch_instruction();
	fetch_data();
}
