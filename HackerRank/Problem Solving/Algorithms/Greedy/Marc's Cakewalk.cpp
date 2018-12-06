#include <vector>
#include <algorithm> // sort

// Complete the marcsCakewalk function below.
long marcsCakewalk(std::vector<int> calorie) {
	std::sort(calorie.begin(), calorie.end(), std::greater<int>());

	long total = 0;
	for (int i = 0; i < calorie.size(); ++i) {
		total += calorie[i] * pow(2, i);
	}
	return total;
}
