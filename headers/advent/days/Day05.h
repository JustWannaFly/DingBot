#pragma once

#include "ADay.h"

#include <vector>

class Day05 : public ADay {
private:
	string part1();
	string part2();
	vector<vector<int>> initVentMap(int maxX, int maxY);
};