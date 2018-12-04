#include <vector>
#include <unordered_set>
#include <algorithm> // max

inline int gen_key(const int &n, const int &m) noexcept {
	return (100 * n) + m; // 0 < n, m < 10
}

// Depth First Search - because we may go many recursive levels deep before
// we even try neighbours of the location specified in the initial call 
void recursive_explore_connected_region(const std::vector<std::vector<int> > &grid, 
	std::unordered_set<int> &region, const int &n, const int &m) {

	if (grid[n][m] == 0 || region.find(gen_key(n, m)) != region.end()) {
		return;
	}

	region.insert(gen_key(n, m));

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {

			if (i == 0 && j == 0) { continue; }

			if (0 <= (n + i) && (n + i) < grid.size() &&
				0 <= (m + j) && (m + j) < grid.front().size()) {

				recursive_explore_connected_region(grid, region, (n + i), (m + j));
			}
		}
	}
}

// Complete the maxRegion function below.
int maxRegion(const std::vector<std::vector<int> > &grid) {
	int maxSize = 0;

	std::unordered_set<int> visited;

	for (int n = 0; n < grid.size(); ++n) {
		for (int m = 0; m < grid.front().size(); ++m) {

			if (grid[n][m] == 1 && visited.find(gen_key(n, m)) == visited.end()) {

				std::unordered_set<int> region;
				recursive_explore_connected_region(grid, region, n, m);

				maxSize = std::max(maxSize, (int)region.size());

				for (auto &e : region) {
					visited.emplace(std::move(e));
				}
			}

		}
	}

	return maxSize;
}