#include <vector>

// Complete the birthday function below.
int birthday(const std::vector<int> &s, int d, int m) {
	// d: sum
	// m: length

	int count = 0;
	for (std::vector<int>::const_iterator it_i = s.cbegin(); it_i != s.cend() - (m - 1); ++it_i) {
		int sum = 0;
		for (std::vector<int>::const_iterator it_j = it_i; it_j != it_i + m; ++it_j) {
			sum += *it_j;
		}
		if (sum == d) {
			++count;
		}
	}
	return count;
}