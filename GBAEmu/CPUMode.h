#pragma once

typedef enum CPUModeType {
	CPUMODE_USER = 0,
	CPUMODE_FIQ = 1,
	CPUMODE_SVC = 2,
	CPUMODE_ABT = 3,
	CPUMODE_IRQ = 4,
	CPUMODE_UND = 5
};