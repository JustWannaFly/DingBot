#include "advent/days/Day06.h"
#include "advent/Input.h"
#include "advent/utils/LanternFishSchool.h"

string Day06::part1() {
	string input = readInputFile("06")[0];
	LanternFishSchool school = LanternFishSchool(parseCSVInts(input));
	int numOfDays = 80;
	for (int i = 0; i < numOfDays; i++) {
		school.stepDay();
	}

	return "After " + to_string(numOfDays) + " days there will be " + to_string(school.getNumOfFish()) + " angler fish.";
}

string Day06::part2() {
	string input = readInputFile("06")[0];
	LanternFishSchool school = LanternFishSchool(parseCSVInts(input));
	int numOfDays = 256;
	for (int i = 0; i < numOfDays; i++) {
		school.stepDay();
	}

	return "After " + to_string(numOfDays) + " days there will be " + to_string(school.getNumOfFish()) + " angler fish.";
}
