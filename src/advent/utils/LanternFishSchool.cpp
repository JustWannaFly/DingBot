#include "advent/utils/LanternFishSchool.h"

LanternFishSchool::LanternFishSchool(vector<int> fishes) {
	zeros = 0;
	ones = 0;
	twos = 0;
	threes = 0;
	fours = 0;
	fives = 0;
	sixes = 0;
	sevens = 0;
	eights = 0;
	for (auto fish : fishes) {
		switch (fish) {
		case 0:
			zeros++;
			break;
		case 1:
			ones++;
			break;
		case 2:
			twos++;
			break;
		case 3:
			threes++;
			break;
		case 4:
			fours++;
			break;
		case 5:
			fives++;
			break;
		case 6:
			sixes++;
			break;
		case 7:
			sevens++;
			break;
		case 8:
			eights++;
			break;
		default:
			break;
		}
	}
}

long long LanternFishSchool::getNumOfFish() {
	return zeros + ones + twos + threes + fours + fives + sixes + sevens + eights;
}

void LanternFishSchool::stepDay() {
	long long oldZeros = zeros;
	zeros = ones;
	ones = twos;
	twos = threes;
	threes = fours;
	fours = fives;
	fives = sixes;
	sixes = sevens + oldZeros;
	sevens = eights;
	eights = oldZeros;
}
