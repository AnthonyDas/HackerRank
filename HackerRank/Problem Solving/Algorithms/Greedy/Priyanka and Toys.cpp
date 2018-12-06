#include <vector>
#include <algorithm> // sort

// Complete the toys function below.
int toys(std::vector<int> w) {
	if (w.empty()) {
		return 0;
	}

	std::sort(w.begin(), w.end());

	int count = 1, min_w = w.front();
	for (std::vector<int>::iterator it = w.begin(); it != w.end(); ++it) {
		if (*it > min_w + 4) {
			++count;
			min_w = *it;
		}
	}

	return count;
}