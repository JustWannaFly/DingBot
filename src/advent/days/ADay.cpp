#include "advent/days/ADay.h"

string ADay::calculate(string part) {
	if (part == "1") {
		return part1();
	}
	if (part == "2") {
		return part2();
	}
	return "Sorry don't have that part....";
}