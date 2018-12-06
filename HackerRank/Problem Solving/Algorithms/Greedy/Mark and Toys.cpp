#include <vector>
#include <algorithm> // sort

// Complete the maximumToys function below.
int maximumToys(std::vector<int> prices, int k) {
	std::sort(prices.begin(), prices.end());

	int count = 0;
	for (auto &p : prices) {
		if (p <= k) {
			k -= p;
			++count;
		}
		else {
			break;
		}
	}

	return count;
}