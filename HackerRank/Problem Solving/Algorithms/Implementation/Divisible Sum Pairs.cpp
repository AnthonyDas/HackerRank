#include <vector>

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, std::vector<int> ar) {
	int count = 0;
	for (std::vector<int>::const_iterator it_i = ar.cbegin(); it_i != ar.cend() - 1; ++it_i) {
		for (std::vector<int>::const_iterator it_j = it_i + 1; it_j != ar.cend(); ++it_j) {
			if ((*it_i + *it_j) % k == 0) {
				++count;
			}
		}
	}
	return count;
}