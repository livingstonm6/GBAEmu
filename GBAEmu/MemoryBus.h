#pragma once
#include <cstdint>
#include "Cartridge.h"
class MemoryBus
{
private:
	Cartridge cart;
public:
	uint8_t read8(uint32_t address);
	uint16_t read16(uint32_t address);
	uint32_t read32(uint32_t address);

	void write(uint32_t address, uint8_t value);
	void write(uint32_t address, uint16_t value);
	void write(uint32_t address, uint32_t value);

	void load_rom(std::string filename);

};

