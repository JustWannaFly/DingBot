#include "advent/days/Day07.h"
#include "advent/Input.h"

string Day07::part1() {
	vector<int> crabPositions = parseCSVInts(readInputFile("07")[0]);
	int maxPos = 0;
	for (int pos : crabPositions) {
		maxPos = max(pos, maxPos);
	}
	vector<int> posFuelCosts;
	for (int i = 0; i <= maxPos; i++) {
		posFuelCosts.push_back(0);
		for (int pos : crabPositions) {
			posFuelCosts[i] += abs(pos - i);
		}
	}
	int cheapestPos = 0;
	int lowestCost = posFuelCosts[0];

	for (int i = 1; i < posFuelCosts.size(); i++) {
		if (lowestCost > posFuelCosts[i]) {
			lowestCost = posFuelCosts[i];
			cheapestPos = i;
		}
	}

	return "The best position is " + to_string(cheapestPos) + " with a fuel cost of " + to_string(lowestCost);
}

string Day07::part2() {
	vector<int> crabPositions = parseCSVInts(readInputFile("07")[0]);
	int maxPos = 0;
	for (int pos : crabPositions) {
		maxPos = max(pos, maxPos);
	}
	vector<int> posFuelCosts;
	for (int i = 0; i <= maxPos; i++) {
		posFuelCosts.push_back(0);
		for (int pos : crabPositions) {
			posFuelCosts[i] += getRisingFuelCost(pos, i);
		}
	}
	int cheapestPos = 0;
	int lowestCost = posFuelCosts[0];

	for (int i = 1; i < posFuelCosts.size(); i++) {
		if (lowestCost > posFuelCosts[i]) {
			lowestCost = posFuelCosts[i];
			cheapestPos = i;
		}
	}

	return "The best position is " + to_string(cheapestPos) + " with a fuel cost of " + to_string(lowestCost);
}

int Day07::getRisingFuelCost(int start, int end)
{
	int diff = abs(start - end);
	// Math formula for sum of first n integers
	int cost = (diff * (diff + 1) / 2);
	return cost;
}
