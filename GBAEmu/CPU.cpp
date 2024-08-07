#include "CPU.h"
#include <iostream>
#include <bitset>

void CPU::fetch_instruction()
{
	uint32_t address = state_.reg.read(REG_PC, state_.mode);
	state_.current_opcode = bus_->read32(address);
	std::cout << "Opcode: " << std::bitset<32>(state_.current_opcode) << std::endl;
	std::cout << "Opcode Bits: " << std::bitset<3>((state_.current_opcode >> 25) & 0b111) << std::endl;

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
	std::cout << "\nSTEP PC: " << std::hex << state_.reg.read(REG_PC, state_.mode) << std::endl;
	fetch_instruction();
	fetch_data();
	executor_.execute(&state_);
}
