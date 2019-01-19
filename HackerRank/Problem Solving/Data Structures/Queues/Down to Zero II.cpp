#include <iostream>
#include <queue>
#include <unordered_set>

// Complete the downToZero function below.
int downToZero(const int &n) {

	std::queue<int> q({ n });
	std::unordered_set<int> visited({ n });

	int move_count = 0, remaining_in_level = q.size();
	while (!q.empty()) {
		const int current = q.front();
		q.pop();

		// Have we reached the target? 
		if (current == 0) {
			return move_count;
		}

		// Largest in pair of factors, i.e. if N = a * b
		// (where a != 1 && b != 1), then we move to max(a, b).
		for (int i = 2; i*i <= current; ++i) {
			if (current % i == 0) {
				const int factor = current / i;

				if (visited.find(factor) == visited.end()) {
					q.push(factor);
					visited.insert(factor);
				}
			}
		}

		// (N - 1)
		q.push(current - 1);
		visited.insert(current - 1);

		// Have we finished traversing at current depth?
		if (!(--remaining_in_level)) {
			remaining_in_level = q.size();
			++move_count;
		}
	}

	return -1;
}