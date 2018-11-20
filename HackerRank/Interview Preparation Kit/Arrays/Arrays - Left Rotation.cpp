#include <vector>

// Complete the rotLeft function below.
std::vector<int> rotLeft(const std::vector<int> &a, int d) {
	std::vector<int> res;

	for (int i = 0; i < a.size(); ++i) {
		res.push_back(a[(i + d) % a.size()]);
	}

	return res;
}