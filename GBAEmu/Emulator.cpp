#include "Emulator.h"
#include <iostream>
#include <string>
#include <filesystem>

const void Emulator::run()
{

	//std::cout << "Enter filename: ";
	std::string file_name = "pkmn.gba";
	//std::getline(std::cin, file_name);

	bus.load_rom(file_name);
	cpu.connect(&bus);

	while (running) {
		cpu.step();
	}
	


}
