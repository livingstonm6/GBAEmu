#include <string>
#include <vector>

class Cartridge{

private:
	// Contains rom data
	std::vector<uint8_t> data;

public:

	// Loads rom file data into vector data
	// if file exists, otherwise exits the program.
	void load_rom(const std::string file_name);

	uint8_t read(uint32_t address);

};