#pragma once

#include <vector>
#include <string>

using namespace std;

class BingoCard {
private:
	vector<vector<int>> cardValues;
	vector<vector<bool>> numCalled;
public:
	void fillCard(vector<string> cardData);
	bool checkNum(int num);
	bool checkBingo();
	int getScore(int multiplier);
};