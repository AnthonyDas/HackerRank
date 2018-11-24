#include <vector>
#include <algorithm> // max
#include <numeric>
#include <iostream>

// Complete the candies function below.
long candies(const int &n, const std::vector<int> &scores) {
	if (scores.empty()) {
		return 0;
	}

	// All kids get 1 sweet at least
	std::vector<int> sweets(n, 1);

	// Left to right
	for (int i = 1; i < n; ++i) {
		if (scores[i] > scores[i - 1]) {
			sweets[i] = sweets[i - 1] + 1;
		}
	}

	// Right to left
	for (int i = n - 2; i >= 0; --i) {
		if (scores[i] > scores[i + 1]) {
			// Should only give more sweets to this kid - not fewer
			sweets[i] = std::max(sweets[i + 1] + 1, sweets[i]);
		}
	}

	/*
	for (auto &s : scores) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
	for (auto &s : sweets) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
	*/

	return std::accumulate(sweets.begin(), sweets.end(), 0L);
}