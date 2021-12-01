#include "advent/days/Day01.h"
#include "advent/Input.h"

string Day01::calculate(string part) {
	if (part == "1") {
		return part1();
	}
	if (part == "2") {
		return part2();
	}
	return "Sorry don't have that part....";
}

string Day01::part1() {
	vector<int> depths = getInputInts("01");
	int timesDeeper = 0;
	for (int i = 0, j = 1; j < depths.size(); i++, j++) {
		if (depths[i] < depths[j]) {
			timesDeeper++;
		}
	}
	return "It got deeper " + to_string(timesDeeper) + " times";
}

string Day01::part2() {
	vector<int> depths = getInputInts("01");
	vector<int> windows;
	for (int i = 0, j = 1, k = 2; k < depths.size(); i++, j++, k++) {
		windows.push_back(depths[i] + depths[j] + depths[k]);
	}

	int timesDeeper = 0;
	for (int i = 0, j = 1; j < windows.size(); i++, j++) {
		if (windows[i] < windows[j]) {
			timesDeeper++;
		}
	}
	return "The windows got deeper " + to_string(timesDeeper) + " times";
}
