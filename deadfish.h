#pragma once
#include <string>
#include <vector>

class RobinfishInterpreter {
public:
	bool mathFix = false; // Fixes deadfish's infamous bug
	bool wrapMode = false; // Variable overflows/underflows like on the 6502.

	std::string process(std::string code); // Returns values in a formatted string.

	inline int getAccumulator() { return acc; }

	void reset();

	std::vector<std::string> getDictionary();

protected:
	inline void opI() { acc += 1; }
	inline void opD() { acc -= 1; }
	inline void opS() { acc *= acc; }
	inline int opO() { return acc; }
	inline void opR() { acc = sqrt(acc); }
	inline void opx2() { acc *= 2; }
	inline void opd2() { acc /= 2; }
	void opH();

	int acc = 0; // Accumulator
};