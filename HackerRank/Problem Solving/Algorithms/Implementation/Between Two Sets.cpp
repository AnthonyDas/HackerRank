#include <vector>

int getTotalX(const std::vector<int> &a, const std::vector<int> &b) {
	int max_a = -1;
	for (std::vector<int>::const_iterator it = a.cbegin(); it != a.cend(); ++it) {
		if (*it > max_a) {
			max_a = *it;
		}
	}

	int min_b = INT_MAX;
	for (std::vector<int>::const_iterator it = b.cbegin(); it != b.cend(); ++it) {
		if (*it < min_b) {
			min_b = *it;
		}
	}

	int count = 0;
	for (int i = max_a; i <= min_b; ++i) {
		bool success = true;
		for (std::vector<int>::const_iterator it = a.cbegin(); it != a.cend(); ++it) {
			if (i % *it != 0) {
				success = false;
				break;
			}
		}
		if (!success) { continue; }

		for (std::vector<int>::const_iterator it = b.cbegin(); it != b.cend(); ++it) {
			if (*it % i != 0) {
				success = false;
				break;
			}
		}
		if (!success) { continue; }

		++count;
	}

	return count;
}