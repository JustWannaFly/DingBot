#pragma once

#include <string>
#include <dpp/dpp.h>

using namespace std;

class ADay
{
private:
	virtual string part1() = 0;
	virtual string part2() = 0;
public:
	virtual string calculate(string part) = 0;
};