#pragma once
#include "Instruction.h"
#include <cinttypes>
class OpcodeDecoder
{
public:
	Instruction decode(uint32_t opcode);
};

