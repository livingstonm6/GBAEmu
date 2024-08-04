#include <string>
#include <vector>

class Cartridge{

private:
	std::vector<uint8_t> data;


public:
	void load_rom(const std::string fileName);


};