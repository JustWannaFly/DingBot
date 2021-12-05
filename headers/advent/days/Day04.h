#pragma once

#include "ADay.h"
#include "advent/utils/BingoCard.h"

class Day04 : public ADay {
private:
	string part1();
	string part2();
	vector<shared_ptr<BingoCard>> getBingoCards(vector<string> rawInput);
};