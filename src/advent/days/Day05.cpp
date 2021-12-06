#include "advent/days/Day05.h"
#include "advent/Input.h"
#include "advent/utils/Line.h"

string Day05::part1()
{
	vector<string> input = readInputFile("05");
	vector<Line> ventLines;
	for (auto row : input) {
		Line line = Line(row);
		if (line.isHorizontal() || line.isVertical()) {
			ventLines.push_back(line);
		}
	}

	int maxX = 0;
	int maxY = 0;
	for (auto line : ventLines) {
		maxX = max(max(maxX, line.end1.x), line.end2.x);
		maxY = max(max(maxY, line.end1.y), line.end2.y);
	}
	auto ventMap = initVentMap(maxX, maxY);
	for (auto line : ventLines) {
		for (auto point : line.getPoints()) {
			if (point.y == 1 && point.x == 2) {
				int foo = 1;
			}
			ventMap[point.y][point.x]++;
		}
	}

	int dangerCount = 0;
	int dangerThreshhold = 2;
	for (auto row : ventMap) {
		for (auto place : row) {
			if (place >= dangerThreshhold) {
				dangerCount++;
			}
		}
	}

	return "There are " + to_string(dangerCount) + " points above the danger threshhold of " + to_string(dangerThreshhold);
}

vector<vector<int>> Day05::initVentMap(int maxX, int maxY)
{
	vector<vector<int>> map;
	for (int i = 0; i <= maxY; i++) {
		map.push_back(vector<int>());
		for (int j = 0; j <= maxX; j++) {
			map[i].push_back(0);
		}
	}
	return map;
}

string Day05::part2()
{
	vector<string> input = readInputFile("05");
	vector<Line> ventLines;
	for (auto row : input) {
		Line line = Line(row);
		ventLines.push_back(line);
	}

	int maxX = 0;
	int maxY = 0;
	for (auto line : ventLines) {
		maxX = max(max(maxX, line.end1.x), line.end2.x);
		maxY = max(max(maxY, line.end1.y), line.end2.y);
	}
	auto ventMap = initVentMap(maxX, maxY);
	for (auto line : ventLines) {
		for (auto point : line.getPoints()) {
			if (point.y == 1 && point.x == 2) {
				int foo = 1;
			}
			ventMap[point.y][point.x]++;
		}
	}

	int dangerCount = 0;
	int dangerThreshhold = 2;
	for (auto row : ventMap) {
		for (auto place : row) {
			if (place >= dangerThreshhold) {
				dangerCount++;
			}
		}
	}

	return "There are " + to_string(dangerCount) + " points above the danger threshhold of " + to_string(dangerThreshhold);
}
