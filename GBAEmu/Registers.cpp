#include "Registers.h"

const uint32_t Registers::read(RegisterType reg, CPUModeType mode)
{
	switch (reg) {
	case REG_R0:
		return r0;
	case REG_R1:
		return r1;
	case REG_R2:
		return r2;
	case REG_R3:
		return r3;
	case REG_R4:
		return r4;
	case REG_R5:
		return r5;
	case REG_R6:
		return r6;
	case REG_R7:
		return r7;
	case REG_R8:
		if (mode == CPUMODE_FIQ) {
			return r8_fiq;
		}
		return r8;

	case REG_R9:
		if (mode == CPUMODE_FIQ) {
			return r9_fiq;
		}
		return r9;

	case REG_R10:
		if (mode == CPUMODE_FIQ) {
			return r10_fiq;
		}
		return r10;

	case REG_R11:
		if (mode == CPUMODE_FIQ) {
			return r11_fiq;
		}
		return r11;

	case REG_R12:
		if (mode == CPUMODE_FIQ) {
			return r12_fiq;
		}
		return r12;

	case REG_R13:
		switch (mode) {
		case CPUMODE_USER:
			return r13;

		case CPUMODE_FIQ:
			return r13_fiq;

		case CPUMODE_SVC:
			return r13_svc;

		case CPUMODE_ABT:
			return r13_abt;

		case CPUMODE_IRQ:
			return r13_irq;

		case CPUMODE_UND:
			return r13_und;
		}

	case REG_R14:
		switch (mode) {
		case CPUMODE_USER:
			return r14;

		case CPUMODE_FIQ:
			return r14_fiq;

		case CPUMODE_SVC:
			return r14_svc;

		case CPUMODE_ABT:
			return r14_abt;

		case CPUMODE_IRQ:
			return r14_irq;

		case CPUMODE_UND:
			return r14_und;
		}

	case REG_R15:
		return r15;


	case REG_CPSR:
		return cpsr;

	case REG_SPSR:
		switch (mode) {
		case CPUMODE_FIQ:
			return spsr_fiq;

		case CPUMODE_SVC:
			return spsr_svc;

		case CPUMODE_ABT:
			return spsr_abt;
		
		case CPUMODE_IRQ:
			return spsr_irq;

		case CPUMODE_UND:
			return spsr_und;

		}
	}
}

void Registers::write(RegisterType reg, uint32_t value, CPUModeType mode)
{
	switch (reg) {
	case REG_R0:
		r0 = value;
	case REG_R1:
		r1 = value;
	case REG_R2:
		r2 = value;
	case REG_R3:
		r3 = value;
	case REG_R4:
		r4 = value;
	case REG_R5:
		r5 = value;
	case REG_R6:
		r6 = value;
	case REG_R7:
		r7 = value;
	case REG_R8:
		if (mode == CPUMODE_FIQ) {
			r8_fiq = value;
		}
		r8 = value;

	case REG_R9:
		if (mode == CPUMODE_FIQ) {
			r9_fiq = value;
		}
		r9 = value;

	case REG_R10:
		if (mode == CPUMODE_FIQ) {
			r10_fiq = value;
		}
		r10 = value;

	case REG_R11:
		if (mode == CPUMODE_FIQ) {
			r11_fiq = value;
		}
		r11 = value;

	case REG_R12:
		if (mode == CPUMODE_FIQ) {
			r12_fiq = value;
		}
		r12 = value;

	case REG_R13:
		switch (mode) {
		case CPUMODE_USER:
			r13 = value;

		case CPUMODE_FIQ:
			r13_fiq = value;

		case CPUMODE_SVC:
			r13_svc = value;

		case CPUMODE_ABT:
			r13_abt = value;

		case CPUMODE_IRQ:
			r13_irq = value;

		case CPUMODE_UND:
			r13_und = value;
		}

	case REG_R14:
		switch (mode) {
		case CPUMODE_USER:
			r14 = value;

		case CPUMODE_FIQ:
			r14_fiq = value;

		case CPUMODE_SVC:
			r14_svc = value;

		case CPUMODE_ABT:
			r14_abt = value;

		case CPUMODE_IRQ:
			r14_irq = value;

		case CPUMODE_UND:
			r14_und = value;
		}

	case REG_R15:
		r15 = value;


	case REG_CPSR:
		cpsr = value;

	case REG_SPSR:
		switch (mode) {
		case CPUMODE_FIQ:
			spsr_fiq = value;

		case CPUMODE_SVC:
			spsr_svc = value;

		case CPUMODE_ABT:
			spsr_abt = value;

		case CPUMODE_IRQ:
			spsr_irq = value;

		case CPUMODE_UND:
			spsr_und = value;

		}
	}



}
