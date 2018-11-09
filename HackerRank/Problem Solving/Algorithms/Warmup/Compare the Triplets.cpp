#include <vector>

// Complete the compareTriplets function below.
std::vector<int> compareTriplets(const std::vector<int> &a, const std::vector<int> &b) {
	int a_score = 0, b_score = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) {
			++a_score;
		}
		else if (b[i] > a[i]) {
			++b_score;
		}
	}

	return std::vector<int> { a_score, b_score };
}