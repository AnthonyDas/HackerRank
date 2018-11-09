#include <iostream>
#include <vector>

// Complete the miniMaxSum function below.
void miniMaxSum(std::vector<int> &arr) {
	int min = INT_MAX, max = 0;
	long long int sum = 0;

	for (std::vector<int>::const_iterator it = arr.cbegin(); it != arr.cend(); ++it) {
		sum += *it;

		if (*it < min) {
			min = *it;
		}
		if (*it > max) {
			max = *it;
		}

	}

	std::cout << (sum - max) << " " << (sum - min);
}
