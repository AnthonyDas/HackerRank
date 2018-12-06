#include <vector>
#include <algorithm> // sort

// HackerRank\HackerRank\Interview Preparation Kit\Greedy Algorithms\Luck Balance.cpp

/*
bool byImportanceDescThenLuckDesc(const std::vector<int> &a, const std::vector<int> &b) {
	if (a.back() != b.back()) {
		return a.back() > b.back();
	}
	return a.front() > b.front();
}


// Complete the luckBalance function below.
int luckBalance(int k, std::vector<std::vector<int> > contests) {
	sort(contests.begin(), contests.end(), byImportanceDescThenLuckDesc);

	int luck = 0;
	for (std::vector<std::vector<int> >::iterator it = contests.begin(); it != contests.end(); ++it) {
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
*/