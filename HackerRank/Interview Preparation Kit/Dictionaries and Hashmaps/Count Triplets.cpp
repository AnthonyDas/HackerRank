#include <vector>
#include <map>

// Complete the countTriplets function below.
long countTriplets(const std::vector<long> &arr, const long &r) {
	// m2 : on arrival of key, counts the pairs that will be formed
	// m3 : on arrival of key, counts the triplets that will be formed
	std::map<long, long> m2, m3;

	long count = 0;
	for (auto &i : arr) {
		// Does this i complete a triple?
		if (m3.count(i)) {
			count += m3[i];
		}

		// Does this i form a pair?
		if (m2.count(i)) {
			m3[i * r] += m2[i];
		}

		// i may always be the start of a new triple 
		++m2[i * r];
	}

	return count;
}