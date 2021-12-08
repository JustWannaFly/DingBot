#include "advent/utils/SegmentDisplay.h"

int SegmentDisplay::matchCount(vector<char> v1, vector<char> v2) {
	int count = 0;
	for (char c1 : v1) {
		for (char c2 : v2) {
			if (c1 == c2) {
				count++;
			}
		}
	}
	return count;
}

void SegmentDisplay::calcDigits(vector<vector<char>> charVectors) {
	digits = { {}, {}, {}, {}, {}, {}, {}, {}, {}, {} };
	for (auto charVector : charVectors) {
		sort(charVector.begin(), charVector.end());
		if (charVector.size() == 2) {
			digits[1] = charVector;
		}
		else if (charVector.size() == 4) {
			digits[4] = charVector;
		}
		else if (charVector.size() == 3) {
			digits[7] = charVector;
		}
		else if (charVector.size() == 7) {
			digits[8] = charVector;
		}
	}
	for (auto charVector : charVectors) {
		if (charVector.size() == 5) {
			if (matchCount(charVector, digits[7]) == 2 &&
				matchCount(charVector, digits[4]) == 3) {
				digits[5] = charVector;
			}
			else if (matchCount(charVector, digits[7]) == 3) {
				digits[3] = charVector;
			}
			else {
				digits[2] = charVector;
			}
		}
	}
	for (auto charVector : charVectors) {
		if (charVector.size() == 6) {
			if (matchCount(charVector, digits[5]) == 5 && 
				matchCount(charVector, digits[3]) == 5) {
				digits[9] = charVector;
			}
			else if (matchCount(charVector, digits[5]) == 4) {
				digits[0] = charVector;
			}
			else {
				digits[6] = charVector;
			}
		}
	}
}

short SegmentDisplay::getNum(vector<char> numChars) {

	for (int i = 0; i < digits.size(); i++) {
		auto testChar = digits[i];
		if (testChar.size() == numChars.size() &&
			matchCount(testChar, numChars) == testChar.size()) {
			return i;
		}
	}
	return -1;
}
