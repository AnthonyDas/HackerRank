#include <vector>

/*
 * Complete the simpleArraySum function below.
 */
int simpleArraySum(const std::vector<int> &ar) {
	int sum = 0;
	for (std::vector<int>::const_iterator it = ar.cbegin(); it != ar.cend(); ++it) {
		sum += *it;
	}
	return sum;
}