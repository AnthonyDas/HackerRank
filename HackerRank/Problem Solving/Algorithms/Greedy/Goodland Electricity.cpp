#include <vector>
#include <algorithm> // min, max

// Complete the pylons function below.
// NB. distribution range is LESS than k.
int pylons(const int &k, std::vector<int> &arr) {
	int count = 0;

	for (int i = 0; i < arr.size(); ++i) {

		bool power = false;

		// Get the indicies of the cities within range
		int start = std::max(0, i - k + 1);
		int end = std::min(i + k - 1, (int)arr.size() - 1);

		// Find the latest city where building a power station is possible
		for (int j = end; j >= start; --j) {
			if (arr[j] == 1) {
				++count;
				i = j + k - 1; // -1 as ++i before next iteration
				power = true;
				break;
			}
		}
		// If unsuccessful - fail.
		if (!power) {
			return -1;
		}
	}

	return count;
}