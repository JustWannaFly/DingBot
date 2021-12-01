#include "advent/days/Day01.h"
#include "advent/Input.h"

string Day01::calculate(string part) {
	int sum = 0;
	vector<int> numbers = getInputInts("01-1");
	for (int number : numbers) {
		sum += number;
	}
	return to_string(sum);
}