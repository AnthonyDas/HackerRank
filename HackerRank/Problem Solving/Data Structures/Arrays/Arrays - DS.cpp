#include <vector>

// Complete the reverseArray function below.
std::vector<int> reverseArray(const std::vector<int> &a) {
	std::vector<int> res;
	for (std::vector<int>::const_reverse_iterator rit = a.crbegin(); rit != a.crend(); ++rit) {
		res.push_back(*rit);
	}
	return res;
}