#include <vector>
#include <stack>
#include <iostream>
#include <algorithm> // max

template <typename T>
void process_window(T &s, std::vector<long> &max_vals, int &c_width, const int &a) {
	while (!s.empty() && s.top().first > a) {
		c_width += s.top().second;
		// Only update if bigger value for the given width
		const int index = c_width - 1; // -1 for 0-indexing
		max_vals[index] = std::max(s.top().first, max_vals[index]);
		s.pop();
	}
}

// Complete the riddle function below.
std::vector<long> riddle(std::vector<long> arr) {
	std::vector<long> max_vals(arr.size(), 0); // Indexing determings width size
	std::stack<std::pair<long, int> > s; // pair: value and width
	int c_width = 0; // cumulative_width

	for (auto &a : arr) {
		c_width = 0;

		// If lower height, process areas now complete
		if (!s.empty() && s.top().first > a) {
			process_window(s, max_vals, c_width, a);
		}

		// Higher height, add to stack
		if (s.empty() || s.top().first < a) {
			s.push(std::pair<int, int>(a, c_width + 1));
		}
		// Same height, extend width
		else if (s.top().first == a) {
			s.top().second += (c_width + 1);
		}
	}

	// End of array - pass zero value to trigger processing
	// anything remaining within stack
	c_width = 0;
	process_window(s, max_vals, c_width, 0);

	// max_vals.back() guaranteed to exists as it's the min element in arr
	long prior = max_vals.back();
	for (auto it = max_vals.rbegin(); it != max_vals.rend(); ++it) {
		// Fill in zeros and realise that right to left sequence must be increasing
		if (*it < prior) {
			*it = prior;
		}
		prior = *it;
	}

	return max_vals;
}