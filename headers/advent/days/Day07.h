#pragma once

#include "ADay.h"

class Day07 : public ADay {
private:
	int getRisingFuelCost(int start, int end);
public:
	string part1();
	string part2();
};
