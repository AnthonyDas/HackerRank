#include <vector>
#include <algorithm> // sort

bool byImportanceDescThenLuckDesc(const std::vector<int> &a, const std::vector<int> &b) {
	if (a.back() != b.back()) {
		return a.back() > b.back();
	}
	return a.front() > b.front();
}


// Complete the luckBalance function below.
// Each contest is described by two integers, L[i] and T[i]:
// - L[i] is the amount of luck associated with a contest. 
// - T[i] denotes the contest's importance rating.
int luckBalance(int k, std::vector<std::vector<int>> contests) {
	std::sort(contests.begin(), contests.end(), byImportanceDescThenLuckDesc);

	int luck = 0;
	for (auto it = contests.cbegin(); it != contests.cend(); ++it) {
		// If important and k > 0 we can afford to lose this contest
		if (it->back() == 1) {
			if (k > 0) {
				luck += it->front(); // Lose
				--k;
			}
			else {
				luck -= it->front(); // Win
			}
		}
		else {
			// Unimportant and can always lose
			luck += it->front(); // Lose
		}
	}

	return luck;
}