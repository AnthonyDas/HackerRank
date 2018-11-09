#include <iostream>
#include <vector>

// Complete the plusMinus function below.
void plusMinus(const std::vector<int> &arr) {
	int pos = 0, neg = 0, zero = 0;

	for (std::vector<int>::const_iterator it = arr.cbegin(); it != arr.cend(); ++it) {
		if (*it < 0) {
			++neg;
		}
		else if (*it > 0) {
			++pos;
		}
		else {
			++zero;
		}
	}

	int total = pos + neg + zero;

	std::cout << round((pos * 1000000.0) / total) / 1000000.0 << std::endl;
	std::cout << round((neg * 1000000.0) / total) / 1000000.0 << std::endl;
	std::cout << round((zero * 1000000.0) / total) / 1000000.0 << std::endl;
}
