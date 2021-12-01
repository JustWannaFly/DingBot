#pragma once

#include <string>
#include <dpp/dpp.h>

using namespace std;

class ADay
{
public:
	virtual string calculate(string part) = 0;
};