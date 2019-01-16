#include <vector>

// Complete the breakingRecords function below.
std::vector<int> breakingRecords(const std::vector<int> &scores) {
	int min = scores.front(), max = scores.front(), min_changes = 0, max_changes = 0;
	for (std::vector<int>::const_iterator it = scores.cbegin(); it != scores.cend(); ++it) {
		if (min > *it) {
			min = *it;
			++min_changes;
		}
		if (max < *it) {
			max = *it;
			++max_changes;

		}
	}
	std::vector<int> res = { max_changes, min_changes };
	return res;
}