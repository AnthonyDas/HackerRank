#include <vector>
#include <algorithm> // sort

// Complete the getMinimumCost function below.
// c: an array of integers representing the original price of each flower
// k: an integer, the number of friends
int getMinimumCost(int k, std::vector<int> c) {
	std::sort(c.begin(), c.end(), std::greater<int>()); // Desc order

	int total = 0;
	for (int i = 0; i < c.size(); ++i) {
		total += ((i / k) + 1) * c[i];
	}

	return total;
}