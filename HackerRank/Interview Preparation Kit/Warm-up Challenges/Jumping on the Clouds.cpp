#include <vector>

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(const std::vector<int> &c) {
	int count = 0;

	for (int i = 0; i < (c.size() - 1); ++i) {
		if (i < (c.size() - 2) && c[i + 2] == 0) {
			++i; // Double jump in conjunction with ++i loop increment
		}
		++count;
	}

	return count;
}