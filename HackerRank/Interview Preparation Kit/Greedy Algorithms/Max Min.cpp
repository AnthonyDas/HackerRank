#include <vector>
#include <algorithm> // sort, min

// Complete the maxMin function below.
// k: an integer, the number of elements in the array to create. (2 <= k)
// arr: an array of integers.
int maxMin(int k, std::vector<int> arr) {
	std::sort(arr.begin(), arr.end());

	int min_unfair = INT_MAX;
	for (int i = 0; i < (arr.size() - (k - 1)); ++i) {
		const int unfair = arr[i + k - 1] - arr[i];
		min_unfair = std::min(unfair, min_unfair);
	}

	return min_unfair;
}
