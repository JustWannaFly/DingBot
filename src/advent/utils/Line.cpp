#include "advent/utils/Line.h"

Point Line::parsePoint(string pointData)
{
	Point p;
	int splitPos = pointData.find(this->coordSeparator);
	p.x = stoi(pointData.substr(0, splitPos));
	p.y = stoi(pointData.substr(splitPos + coordSeparator.size(), pointData.size()));
	return p;
}

Line::Line(string data) {
	int splitPos = data.find(this->pointSeparator);
	end1 = parsePoint(data.substr(0, splitPos));
	end2 = parsePoint(data.substr(splitPos + pointSeparator.size(), data.size()));
}

vector<Point> Line::getPoints()
{
	vector<Point> points;
	points.push_back(end1);
	int curX = end1.x;
	int curY = end1.y;
	// This assumes lines are horizontal, vertical, or on a 45 degree slope.
	while (curX != end2.x || curY != end2.y) {
		if (end1.x > end2.x) {
			curX--;
		}
		else if (end1.x < end2.x) {
			curX++;
		}
		if (end1.y > end2.y) {
			curY--;
		}
		else if (end1.y < end2.y) {
			curY++;
		}
		points.push_back(Point(curX, curY));
	}
	return points;
}

bool Line::isHorizontal()
{
	return end1.y == end2.y;
}

bool Line::isVertical()
{
	return end1.x == end2.x;
}
