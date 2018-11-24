#include <vector>
#include <algorithm>

// Complete the maxSubsetSum function below.
int maxSubsetSum(const std::vector<int> &arr) {
	// Cumulative max - insert two dummy zeros to be
	//  two elements before the start of given arr
	std::vector<int> max_cum(2, 0);

	// The cumulative max is the greater of either:
	// - the sum of the current value (>0) plus the cumulative max from two steps back
	// - the cumulative max from previous step
	for (int i = 0; i < arr.size(); ++i) {
		const int curr = arr[i] > 0 ? arr[i] : 0;
		max_cum.push_back(std::max(max_cum[i] + curr, max_cum.back()));
	}

	return max_cum.back();
}