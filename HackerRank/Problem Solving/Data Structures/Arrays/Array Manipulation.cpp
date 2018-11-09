#include <vector>
#include <algorithm>

// Complete the arrayManipulation function below.
long long int arrayManipulation(const int &n, const std::vector<std::vector<int> > &queries) {
	std::vector<long long int> arr(n, 0);

	for (int i = 0; i < queries.size(); ++i) {
		int a = queries[i][0], b = queries[i][1], k = queries[i][2];

		/*for (int j = a; j <= b; ++j) {
			arr[j - 1] += k;
		}*/

		// Instead of updating every element between a and b inclusive,
		// let's take the approach that the values along arr should be
		// cumulative. Then we only need to add k to element a and minus
		// k to element (b+1).

		arr[a - 1] += k; // -1 as 1-indexed
		if (b < arr.size()) {
			arr[b] += -k;
		}
	}

	long long int res = 0, val = 0;
	for (int i = 0; i < arr.size(); ++i) {
		val += arr[i];
		res = std::max(res, val);
	}
	return res;
}