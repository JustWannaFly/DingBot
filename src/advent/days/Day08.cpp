#include "advent/days/Day08.h"
#include "advent/Input.h"
#include "advent/utils/SegmentDisplay.h"

string Day08::part1()
{
	vector<string> input = readInputFile("08");

	int count = 0;
	int pos;
	string piece;
	vector<int> uniqueLengths = { 2, 3, 4, 7 };
	for (string line : input) {
		pos = line.find("|");
		line.erase(0, pos + 2);
		line += " ";
		while ((pos = line.find(" ")) != string::npos) {
			piece = line.substr(0, pos);
			line.erase(0, pos + 1);
			if (std::count(uniqueLengths.begin(), uniqueLengths.end(), piece.size())) {
				count++;
			}
		}
	}

	return "There were " + to_string(count) + " instances of a 1, 4, 7, or 8";
}

string Day08::part2()
{
	vector<string> input = readInputFile("08");

	int sum = 0;
	int pos;
	vector<int> outputDigits;
	vector<string> allDigits;
	vector<vector<char>> allDigitChars;
	vector<string> outputCode;
	vector<int> uniqueLengths = { 2, 3, 4, 7 };
	SegmentDisplay disp;
	for (string line : input) {
		pos = line.find("|");
		allDigits = parseStrVector(line.substr(0, pos), " ");
		outputCode = parseStrVector(line.substr(pos + 1, line.size()), " ");
		for (auto digitStr : allDigits) {
			vector<char> chars;
			copy(digitStr.begin(), digitStr.end(), std::back_inserter(chars));
			allDigitChars.push_back(chars);
		}
		disp.calcDigits(allDigitChars);
		outputDigits.clear();
		for (auto digitStr : outputCode) {
			vector<char> chars;
			copy(digitStr.begin(), digitStr.end(), std::back_inserter(chars));
			outputDigits.push_back(disp.getNum(chars));
		}
		sum += (1000 * outputDigits[0] + 100 * outputDigits[1] + 10 * outputDigits[2] + outputDigits[3]);
	}

	return "The sum of all the output is " + to_string(sum);
}
