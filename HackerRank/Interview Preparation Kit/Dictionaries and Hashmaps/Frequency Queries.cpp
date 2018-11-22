#include <vector>
#include <map>

// Complete the freqQuery function below.
// Each query is of the form two integers described below:
// - 1 x: Insert x in your data structure.
// - 2 y: Delete one occurence of y from your data structure, if present.
// - 3 z: Check if any integer is present whose frequency is exactly y. If yes, print 1 else 0.
std::vector<int> freqQuery(const std::vector<std::vector<int> > &queries) {
	std::vector<int> res;

	std::map<int, int> m; // Value and frequency count
	std::map<int, int> f; // Frequency count, counts
	for (auto &q : queries) {
		if (q.front() == 1) {
			int freq = ++m[q.back()];
			++f[freq];
			--f[--freq];
		}
		else if (q.front() == 2) {
			auto it = m.find(q.back());
			if (it != m.end()) {
				if (it->second > 1) {
					int freq = --(it->second);
					++f[freq];
					--f[++freq];
				}
				else {
					m.erase(it);
					--f[1];
				}
			}
		} else { // q.front() == 3
			const bool found = f[q.back()] > 0;
			res.emplace_back(found ? 1 : 0);
		}
	}

	return res;
}