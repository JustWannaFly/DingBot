#include "advent/days/Day04.h"
#include "advent/Input.h"
#include "advent/utils/BingoCard.h"
#include <set>

string Day04::part1() {
	vector<string> input = readInputFile("04");
	vector<int> calledNumbers = parseCSVInts(input[0]);
	auto cards = getBingoCards(input);
	
	int winningCard = -1;
	int triggerNum = -1;
	for (auto num : calledNumbers) {
		if (winningCard == -1) {
			for (int i = 0; i < cards.size(); i++) {
				bool found = cards[i]->checkNum(num);
				bool isBingo = false;
				if (found) {
					isBingo = cards[i]->checkBingo();
				}
				if (isBingo) {
					winningCard = i;
					triggerNum = num;
					break;
				}
			}
		}
	}
	if (winningCard == -1) {
		return "There is no winning card";
	}

	int score = cards[winningCard]->getScore(triggerNum);

	return "The first winning card is card " + to_string(winningCard) + " when the number " +
		to_string(triggerNum) + " is called with a score of " + to_string(score);
}

string Day04::part2() {
	vector<string> input = readInputFile("04");
	vector<int> calledNumbers = parseCSVInts(input[0]);
	auto cards = getBingoCards(input);

	set<int> winningCards;
	int lastCard = -1;
	int triggerNum = -1;
	for (auto num : calledNumbers) {
		if (winningCards.size() < cards.size()) {
			for (int i = 0; i < cards.size(); i++) {
				bool found = cards[i]->checkNum(num);
				bool isBingo = false;
				if (found) {
					isBingo = cards[i]->checkBingo();
				}
				if (isBingo) {
					winningCards.insert(i);
					if (winningCards.size() == cards.size()) {
						lastCard = i;
						triggerNum = num;
						break;
					}
				}
			}
		}
	}

	int score = cards[lastCard]->getScore(triggerNum);

	return "The last winning card is card " + to_string(lastCard) + " when the number " +
		to_string(triggerNum) + " is called with a score of " + to_string(score);
}

vector<shared_ptr<BingoCard>> Day04::getBingoCards(vector<string> rawInput)
{
	vector<shared_ptr<BingoCard>> cards;
	vector<string> cardData;
	for (int i = 1; i < rawInput.size(); i++) {
		if (rawInput[i] == "") {
			if (cardData.size() != 0) {
				auto card = shared_ptr<BingoCard>(new BingoCard());
				card->fillCard(cardData);
				cards.push_back(card);
				cardData.clear();
			}
		}
		else {
			cardData.push_back(rawInput[i]);
		}
	}
	auto card = shared_ptr<BingoCard>(new BingoCard());
	card->fillCard(cardData);
	cards.push_back(card);
	return cards;
}
