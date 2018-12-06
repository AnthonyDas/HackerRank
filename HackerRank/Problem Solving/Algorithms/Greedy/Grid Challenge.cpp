#include <vector>
#include <algorithm>
#include <string>

// Complete the gridChallenge function below.
std::string gridChallenge(std::vector<std::string> grid) {
	if (grid.empty()) {
		return "YES";
	}

	for (std::vector<std::string>::iterator it = grid.begin(); it != grid.end(); ++it) {
		std::sort(it->begin(), it->end()); // Sort each string
	}

	for (int j = 0; j < grid.front().size(); ++j) {
		for (int i = 0; i < grid.size() - 1; ++i) {
			if (grid[i][j] > grid[i + 1][j]) {
				return "NO";
			}
		}
	}

	return "YES";
}