#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;

class SegmentDisplay {
private:
	int matchCount(vector<char> v1, vector<char> v2);
	vector<vector<char>> digits;
public:
	void calcDigits(vector<vector<char>> charVectors);
	short getNum(vector<char> numChars);
};
