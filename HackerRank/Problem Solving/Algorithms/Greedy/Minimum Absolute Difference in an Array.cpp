#include <vector>
#include <algorithm> // sort

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(std::vector<int> arr) {
	std::sort(arr.begin(), arr.end());

	int min_diff = INT_MAX;
	for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end() - 1; ++it) {
		if ((*(it + 1) - *it) < min_diff) {
			min_diff = (*(it + 1) - *it);
		}
	}
	return min_diff;
}
