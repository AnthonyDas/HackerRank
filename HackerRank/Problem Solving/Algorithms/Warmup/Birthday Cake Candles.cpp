#include <vector>

// Complete the birthdayCakeCandles function below.
int birthdayCakeCandles(const std::vector<int> &ar) {
	int max = 0, count = 0;
	for (std::vector<int>::const_iterator it = ar.cbegin(); it != ar.cend(); ++it) {
		if (*it > max) {
			max = *it;
			count = 1;
		}
		else if (*it == max) {
			++count;
		}
	}

	return count;
}
