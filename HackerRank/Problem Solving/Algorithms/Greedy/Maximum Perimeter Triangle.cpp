#include <vector>
#include <algorithm> // sort


// Complete the maximumPerimeterTriangle function below.
std::vector<int> maximumPerimeterTriangle(std::vector<int> sticks) {
	std::sort(sticks.begin(), sticks.end());

	std::vector<int> res;
	for (int i = (sticks.size() - 1); i > 1; --i) {
		if (sticks[i] < sticks[i - 1] + sticks[i - 2]) {
			res.push_back(sticks[i - 2]);
			res.push_back(sticks[i - 1]);
			res.push_back(sticks[i]);
			return res;
		}
	}

	// Should return above
	res.push_back(-1);
	return res;
}