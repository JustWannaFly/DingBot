#include "advent/utils/BingoCard.h"

void BingoCard::fillCard(vector<string> cardData) {

    for (auto line : cardData) {
        line = line + " ";
        int pos;
        vector<int> row;
        vector<bool> calledRow;
        while ((pos = line.find(" ")) != string::npos) {
            string part = line.substr(0, pos);
            if (part != "") {
                row.push_back(stoi(part));
                calledRow.push_back(false);
            }
            line.erase(0, pos + 1);
        }
        cardValues.push_back(row);
        numCalled.push_back(calledRow);
	}
}

bool BingoCard::checkNum(int num) {
    for (int i = 0; i < cardValues.size(); i++) {
        for (int j = 0; j < cardValues[0].size(); j++) {
            if (cardValues[i][j] == num) {
                numCalled[i][j] = true;
                return true;
            }
        }
    }
    return false;
}

bool BingoCard::checkBingo()
{
    vector<int> winningNums;

    for (int i = 0; i < numCalled.size(); i++) {
        if (numCalled[i][0]) {
            winningNums.push_back(cardValues[i][0]);
            for (int j = 1; j < numCalled[0].size(); j++) {
                if (numCalled[i][j]) {
                    winningNums.push_back(cardValues[i][j]);
                    if (winningNums.size() == numCalled[0].size()) {
                        return true;
                    }
                }
                else {
                    winningNums.clear();
                    break;
                }
            }
        }
    }
    if (winningNums.size() == 0) {
        for (int i = 0; i < numCalled[0].size(); i++) {
            if (numCalled[0][i]) {
                winningNums.push_back(cardValues[0][i]);
                for (int j = 1; j < numCalled.size(); j++) {
                    if (numCalled[j][i]) {
                        winningNums.push_back(cardValues[j][i]);
                        if (winningNums.size() == numCalled.size()) {
                            return true;
                        }
                    }
                    else {
                        winningNums.clear();
                        break;
                    }
                }
            }
        }
    }
    return false;
}

int BingoCard::getScore(int multiplier)
{
    int unmarkedSum = 0;
    for (int i = 0; i < numCalled.size(); i++) {
        for (int j = 0; j < numCalled[0].size(); j++) {
            if (!numCalled[i][j]) {
                unmarkedSum += cardValues[i][j];
            }
        }
    }
    
    return unmarkedSum * multiplier;
}
