#pragma once

#include <vector>

using namespace std;

class LanternFishSchool {
private:
	long long zeros;
	long long ones;
	long long twos;
	long long threes;
	long long fours;
	long long fives;
	long long sixes;
	long long sevens;
	long long eights;
public:
	LanternFishSchool(vector<int> fish);
	long long getNumOfFish();
	void stepDay();
};