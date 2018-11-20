#include <vector>
#include <map>

// Complete the sockMerchant function below.
int sockMerchant(int n, const std::vector<int> &ar) {
	
	std::map<int, int> m;
	for (auto &s : ar) {
		++m[s];
	}

	int count = 0;
	for (auto &sc : m) {
		count += (sc.second / 2);
	}

	return count;
}