#include <vector>

// Complete the aVeryBigSum function below.
long long int aVeryBigSum(const std::vector<long> &ar) {
	long long int sum = 0;
	for (std::vector<long>::const_iterator it = ar.cbegin(); it != ar.cend(); ++it) {
		sum += *it;
	}
	return sum;
}