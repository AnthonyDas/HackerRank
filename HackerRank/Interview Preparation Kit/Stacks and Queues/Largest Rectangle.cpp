#include <vector>
#include <stack>
#include <algorithm> // std::max

template <typename T>
void process_completed_areas(T &s, long &max_area, int &c_width, const int &h) {
	while (!s.empty() && s.top().first > h) {
		c_width += s.top().second;
		long area = s.top().first * c_width;
		max_area = std::max(max_area, area);
		s.pop();
	}
}

// Complete the largestRectangle function below.
long largestRectangle(const std::vector<int> &heights) {
	std::stack<std::pair<int, int> > s; // pair: height and width
	long max_area = 0;
	int c_width = 0; // cumulative_width

	for (auto &h : heights) {
		c_width = 0;

		// If lower height, process areas now complete
		if (!s.empty() && s.top().first > h) {
			process_completed_areas(s, max_area, c_width, h);
		}

		// Higher height, add to stack
		if (s.empty() || s.top().first < h) {
			s.push(std::pair<int, int>(h, c_width + 1));
		}
		// Same height, extend width
		else if (s.top().first == h) {
			s.top().second += (c_width + 1);
		}
	}

	// End of buildings - pass zero height to trigger processing
	// anything remaining within stack
	c_width = 0;
	process_completed_areas(s, max_area, c_width, 0);

	return max_area;
}