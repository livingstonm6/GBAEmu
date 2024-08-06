#include "MemoryBus.h"
#include <iostream>

uint8_t MemoryBus::read8(uint32_t address)
{
	if (0x08000000 <= address < 0x0A000000) {


		std::cout << "Bus read address: " << std::hex << address << std::endl;

		return cart.read(address - 0x08000000);
	}

	std::cerr << "Unsupported address during bus read: " << std::hex << address << std::endl;
	exit(-2);
}

uint16_t MemoryBus::read16(uint32_t address)
{
	uint8_t lower = read8(address);
	uint8_t upper = read8(address + 1);

	return lower | (upper << 8);
}

uint32_t MemoryBus::read32(uint32_t address)
{
	uint16_t lower = read16(address);
	uint16_t upper = read16(address + 2);

	return lower | (upper << 16);
}

void MemoryBus::load_rom(std::string filename)
{
	cart.load_rom(filename);
}
