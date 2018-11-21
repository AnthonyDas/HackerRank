#include <vector>
#include <algorithm> // sort

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(std::vector<int> arr) {
	std::sort(arr.begin(), arr.end());

	int min_diff = INT_MAX;
	for (std::vector<int>::const_iterator it = arr.cbegin(); it != arr.cend() - 1; ++it) {
		const int diff = (*(it + 1) - *it);
		if (diff < min_diff) {
			min_diff = diff;
		}
	}
	return min_diff;
}