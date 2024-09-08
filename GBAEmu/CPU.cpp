#include "CPU.h"
#include <iostream>
#include <bitset>
#include "Instruction.h"

void CPU::fetch_instruction()
{
	uint32_t address = state_.reg.read(REG_PC, state_.mode);
	state_.current_opcode = bus_->read32(address);
	std::cout << "Opcode: " << std::bitset<32>(state_.current_opcode) << std::endl;
	state_.current_instruction = decoder_.decode(state_.current_opcode);

}

void CPU::fetch_data()
{
	std::cout << state_.current_instruction.get_name() << std::endl;
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
