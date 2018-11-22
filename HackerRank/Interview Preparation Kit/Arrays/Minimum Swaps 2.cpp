#include <vector>
#include "swap.h"

// Complete the minimumSwaps function below.
int minimumSwaps(std::vector<int> arr) {
	int count = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] != (i + 1)) {
			for (int j = (i + 1); j < arr.size(); ++j) {
				if (arr[j] == (i + 1)) {

					swap(arr[i], arr[j]);
					++count;
					break;
				}
			}
		}
	}

	return count;
}