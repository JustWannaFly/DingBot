#pragma once

#include <string>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

class Line {
private:
	string pointSeparator = " -> ";
	string coordSeparator = ",";
	Point parsePoint(string pointData);
public:
	Line(string data);
	bool isHorizontal();
	bool isVertical();
	vector<Point> getPoints();
	Point end1;
	Point end2;
};