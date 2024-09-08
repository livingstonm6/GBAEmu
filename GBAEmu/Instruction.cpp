#include "Instruction.h"

Instruction::Instruction(std::string input)
{
    name_ = input;
}

std::string Instruction::get_name()
{
    return name_;
}
