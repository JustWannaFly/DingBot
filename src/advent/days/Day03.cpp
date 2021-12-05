#include "advent/days/Day03.h"
#include "advent/Input.h"

string Day03::part1() {
	vector<string> inputs = readInputFile("03");
	vector<int> oneCounts = {};
	for (auto c : inputs[0]) {
		oneCounts.push_back(0);
	}

	for (auto line : inputs) {
		int pos = 0;
		for (char& c : line) {
			if (c == '1') {
				oneCounts[pos]++;
			}
			pos++;
		}
	}
	string gamma;
	string epsilon;
	int cutoff = inputs.size() / 2;

	for (auto ones : oneCounts) {
		if (ones > cutoff) {
			gamma += '1';
			epsilon += '0';
		}
		else {
			gamma += '0';
			epsilon += '1';
		}
	}
	int gammaInt = binaryToNum(gamma);
	int epsilonInt = binaryToNum(epsilon);

	return "Power consumption is " + to_string(gammaInt * epsilonInt);
}

string Day03::part2() {
	vector<string> inputs = readInputFile("03");
	vector<string> possibleMostValues = inputs;
	vector<string> possibleLeastValues = inputs;
	vector<string> zeros;
	vector<string> ones;

	for (int i = 0; i < possibleMostValues[0].size() && possibleMostValues.size() > 1; i++) {
		zeros.clear();
		ones.clear();
		for (int j = 0; j < possibleMostValues.size(); j++) {
			if (possibleMostValues[j][i] == '0') {
				zeros.push_back(possibleMostValues[j]);
			}
			else {
				ones.push_back(possibleMostValues[j]);
			}
		}
		if (ones.size() >= zeros.size()) {
			possibleMostValues = ones;
		}
		else {
			possibleMostValues = zeros;
		}
	}

	for (int i = 0; i < possibleLeastValues[0].size() && possibleLeastValues.size() > 1; i++) {
		zeros.clear();
		ones.clear();
		for (int j = 0; j < possibleLeastValues.size(); j++) {
			if (possibleLeastValues[j][i] == '0') {
				zeros.push_back(possibleLeastValues[j]);
			}
			else {
				ones.push_back(possibleLeastValues[j]);
			}
		}
		if (ones.size() < zeros.size()) {
			possibleLeastValues = ones;
		}
		else {
			possibleLeastValues = zeros;
			
		}
	}
	int co2 = binaryToNum(possibleLeastValues[0]);
	int o2 = binaryToNum(possibleMostValues[0]);
	return "Life Support rating is " + to_string(binaryToNum(possibleLeastValues[0]) * binaryToNum(possibleMostValues[0]));
}

int Day03::binaryToNum(string s) {
	int toAdd = 1;
	int num = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			num += toAdd;
		}
		toAdd = toAdd * 2;
	}
	return num;
}
