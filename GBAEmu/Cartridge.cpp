#include "Cartridge.h"
#include <fstream>
#include <iostream>

void Cartridge::load_rom(const std::string fileName)
{
	std::ifstream file;
	file.open(fileName, std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		exit(-1);
	}

	file.seekg(0, std::ios::end);
	std::streampos fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	data.resize(static_cast<std::size_t>(fileSize));

	file.read(reinterpret_cast<char *>(data.data()), fileSize);

	file.close();

	// Display game title

	int current = 0x108;
	const int end = 0x128;

	std::string title;

	while (current <= end) {

		title += data[current];

		current++;
	}

	std::cout << "Game title: " << title << std::endl;

}
