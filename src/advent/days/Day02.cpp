#include "advent/days/Day02.h"
#include "advent/Input.h"

string Day02::part1() {
	vector<string> inputs = readInputFile("02");
	int horizontal = 0;
	int vertical = 0;
	for (auto line : inputs) {
		if (line.find("forward") == 0) {
			horizontal += parseInt(line.back());
		} else if (line.find("down") == 0) {
			vertical += parseInt(line.back());
		} else if (line.find("up") == 0) {
			vertical -= parseInt(line.back());
		}
	}
	int totalDist = horizontal * vertical;
	return "You went " + to_string(totalDist);
}

string Day02::part2() {
	vector<string> inputs = readInputFile("02");
	int horizontal = 0;
	int vertical = 0;
	int aim = 0;
	for (auto line : inputs) {
		if (line.find("forward") == 0) {
			int step = parseInt(line.back());
			horizontal += step;
			vertical += step * aim;
		}
		else if (line.find("down") == 0) {
			aim += parseInt(line.back());
		}
		else if (line.find("up") == 0) {
			aim -= parseInt(line.back());
		}
	}
	int totalDist = horizontal * vertical;
	return "You went " + to_string(totalDist);
}

int Day02::parseInt(char c) {
	return c - '0';
}
