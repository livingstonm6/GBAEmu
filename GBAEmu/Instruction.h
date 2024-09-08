#pragma once
#include <string>
class Instruction
{

	std::string name_;
public:
	Instruction(std::string input);

	std::string get_name();
};

