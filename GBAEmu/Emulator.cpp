#include "Emulator.h"
#include <iostream>
#include <string>
#include <filesystem>

const void Emulator::run()
{

	std::cout << "Enter filename: ";
	std::string fileName;
	std::getline(std::cin, fileName);

	cart.load_rom(fileName);
	

}
