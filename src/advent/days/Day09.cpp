#include "advent/days/Day09.h"
#include "advent/Input.h"
#include <set>


inline int charToInt(char c) {
	return c - '0';
}

inline int getRisk(int height) {
	return height + 1;
}
struct Coords {
	Coords(int x, int y) : x(x), y(y) {};
	bool operator==(const Coords& other) const {
		return this->x == other.x && this->y == other.y;
	};
	bool operator<(const Coords& other) const {
		if (this->x < other.x) {
			return true;
		}
		if (this->x > other.x) {
			return false;
		}
		if (this->y < other.y) {
			return true;
		}
		return false;
	}
	int x, y;
};
struct Basin {
	Basin(Coords lowPoint, int size) : lowPoint(lowPoint), size(size) {};

	Coords lowPoint;
	int size;
};
struct FloorMap {
	vector<vector<int>> map;

	FloorMap(vector<string> lines) {
		for (int i = 0; i < lines.size(); i++) {
			map.push_back(vector<int>());
			string line = lines[i];
			for (int j = 0; j < line.size(); j++) {
				map[i].push_back(charToInt(line[j]));
			}
		}
	};

	int getHeight(Coords loc) {
		return map[loc.x][loc.y];
	}

	int getBasinSize(Coords lowPoint) {
		set<Coords> basin;
		set<Coords> newLocations;
		newLocations.insert(lowPoint);
		while (newLocations.size()) {
			for (auto it = newLocations.begin(); it != newLocations.end(); ++it) {
				basin.insert(*it);
			}
			auto currentLocations = newLocations;
			newLocations.clear();
			for (auto it = currentLocations.begin(); it != currentLocations.end(); ++it) {
				auto neighbors = getNeighbors(*it);
				for (auto jt = neighbors.begin(); jt != neighbors.end(); ++jt) {
					int neighborHeight = getHeight(*jt);
					bool isInBasin = basin.count(*jt);
					if (neighborHeight != 9 && neighborHeight > getHeight(*it) && !isInBasin) {
						newLocations.insert(*jt);
					}
				}
			}
		}
		return basin.size();
	}

	vector<Coords> getLowPoints() {
		vector<Coords> lowPoints;

		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				auto neighbors = getNeighbors(Coords(i, j));
				bool isLowest = true;
				for (auto it = begin(neighbors); it != end(neighbors); ++it) {
					if (getHeight(*it) <= map[i][j]) {
						isLowest = false;
					}
				}
				if (isLowest) {
					lowPoints.push_back(Coords(i, j));
				}
			}
		}

		return lowPoints;
	}
	vector<Coords> getNeighbors(Coords coords) {
		int x = coords.x;
		int y = coords.y;
		vector<Coords> neighbors;
		if (x > 0) {
			neighbors.push_back(Coords(x - 1, y));
		}
		if (x < map.size() - 1) {
			neighbors.push_back(Coords(x + 1, y));
		}
		if (y > 0) {
			neighbors.push_back(Coords(x, y - 1));
		}
		if (y < map[x].size() - 1) {
			neighbors.push_back(Coords(x, y + 1));
		}
		return neighbors;
	}
};

string Day09::part1() {
	vector<string> input = readInputFile("09");
	FloorMap map = FloorMap(input);
	int riskSum = 0;
	vector<Coords> lowPoints = map.getLowPoints();
	for (auto it = std::begin(lowPoints); it != std::end(lowPoints); ++it) {
		riskSum += getRisk(map.getHeight(*it));
	}
	return "The total risk level is " + to_string(riskSum);
}

string Day09::part2() {
	vector<string> input = readInputFile("09");
	FloorMap map = FloorMap(input);
	vector<Coords> lowPoints = map.getLowPoints();
	vector<Basin> basins;
	for (auto it = std::begin(lowPoints); it != std::end(lowPoints); ++it) {
		basins.push_back(Basin(*it, map.getBasinSize(*it)));
	}

	while (basins.size() > 3) {
		int smallPos = 0;
		int smallSize = -1;
		for (int i = 0; i < basins.size(); i++) {
			if (smallSize == -1 || basins[i].size < smallSize) {
				smallPos = i;
				smallSize = basins[i].size;
			}
		}
		basins.erase(basins.begin() + smallPos);
	}

	int sizeProduct = 1;

	for (auto it = basins.begin(); it != basins.end(); ++it) {
		sizeProduct *= it->size;
	}

	return "The product of the 3 largest basins's sizes is " + to_string(sizeProduct);
}
