#include "OpcodeDecoder.h"
#include <iostream>

Instruction OpcodeDecoder::decode(uint32_t opcode)
{
    int temp = (opcode >> 25) & 0b111;
    if (temp = 0b001) {
        return Instruction("Data Processing/PSR Transfer");
    }

    temp = (opcode >> 22) & 0b111111;
    int temp2 = (opcode >> 4) & 0b1111;
    if (temp == 0 && temp2 == 0b1001) {
        return Instruction("Multiply");
    }

    temp = (opcode >> 23) & 0b11111;
    if (temp == 0b00001 && temp2 == 0b1001) {
        return Instruction("Multiply Long");
    }

    temp2 = (opcode >> 20) & 0b11;
    int temp3 = (opcode >> 4) & 0b11111111;
    if (temp == 0b00010 && temp2 == 0 && temp3 == 0b00001001) {
        return Instruction("Single Data Swap");
    }

    temp = (opcode >> 4) & 0b111111111111111111111111;
    if (temp == 0b000100101111111111110001) {
        return Instruction("Branch and Exchange");
    }

    temp = (opcode >> 25) & 0b111;
    temp2 = (opcode >> 22) & 1;
    temp3 = (opcode >> 7) & 0b11111;
    int temp4 = (opcode >> 4) & 1;
    if (temp == 0 && temp2 == 0 && temp3 == 1 && temp4 == 1) {
        return Instruction("Halfword Data Transfer (reg offset)");
    }

    temp3 &= 1;
    
    if (temp == 0 && temp2 == 1 && temp3 == 1 && temp4 == 1) {
        return Instruction("Halfword Data Transfer (immediate offset)");
    }

    temp = (opcode >> 26) & 0b11;
    if (temp == 0b01) {
        return Instruction("Single Data Transfer");
    }

    temp = (opcode >> 25) & 0b111;
    if (temp == 0b100) {
        return Instruction("Block Data Transfer");
    }

    if (temp == 0b101) {
        return Instruction("Branch");
    }
    
    if (temp == 0b110) {
        return Instruction("Coprocessor Data Transfer");
    }

    temp = (opcode >> 25) & 0b1111;
    temp2 = (opcode >> 4) & 0b1;

    if (temp == 0b1110 && temp2 == 0) {
        return Instruction("Coprocessor Data Operation");
    }
    if (temp == 0b1110 && temp2 == 1) {
        return Instruction("Coprocessor Register Transfer");
    }
    if (temp == 0b1111) {
        return Instruction("Software Interrupt");
    }
                        

    std::cerr << "Error: Unrecognized Opcode" << std::endl;
    exit(-1);
}
