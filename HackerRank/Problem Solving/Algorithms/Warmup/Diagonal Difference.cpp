#include <vector>

// Complete the diagonalDifference function below.
int diagonalDifference(const std::vector<std::vector<int> > &arr) {
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < arr.size(); ++i) {
		sum1 += arr[i][i];
		sum2 += arr[arr.size() - 1 - i][i];
	}

	return abs(sum1 - sum2);
}