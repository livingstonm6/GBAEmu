#pragma once
#include <cstdint>
#include "CPUMode.h"

enum RegisterType {
	REG_0 = 0,
	REG_1 = 1,
	REG_2 = 2,
	REG_3 = 3,
	REG_4 = 4,
	REG_5 = 5,
	REG_6 = 6, 
	REG_7 = 7, 
	REG_8 = 8,
	REG_9 = 9, 
	REG_10 = 10,
	REG_11 = 11,
	REG_12 = 12,
	REG_13 = 13,
	REG_14 = 14,
	REG_15 = 15,
	REG_CPSR = 16,
	REG_SPSR = 17,
	
	// alternative names for r13-15:
	// Stack pointer, link register, and program counter
	REG_SP = 13,
	REG_LR = 14,
	REG_PC = 15
};

class Registers
{
private:
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;

	uint32_t r8;
	uint32_t r8_fiq;

	uint32_t r9;
	uint32_t r9_fiq;

	uint32_t r10;
	uint32_t r10_fiq;

	uint32_t r11;
	uint32_t r11_fiq;

	uint32_t r12;
	uint32_t r12_fiq;

	uint32_t r13;
	uint32_t r13_fiq;
	uint32_t r13_svc;
	uint32_t r13_abt;
	uint32_t r13_irq;
	uint32_t r13_und;

	uint32_t r14;
	uint32_t r14_fiq;
	uint32_t r14_svc;
	uint32_t r14_abt;
	uint32_t r14_irq;
	uint32_t r14_und;

	// Program counter starts at 0 the beginning of ROM data
	uint32_t r15 = 0x08000000;

	uint32_t cpsr;
	uint32_t spsr_fiq;
	uint32_t spsr_svc;
	uint32_t spsr_abt;
	uint32_t spsr_irq;
	uint32_t spsr_und;

public:

	const uint32_t read(RegisterType reg, CPUModeType mode);
	void write(RegisterType reg, uint32_t value, CPUModeType mode);

};

