#include <string>
#include <vector>
#include <algorithm> // max

// Longest common subsequence (LCS) problem
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

// Complete the commonChild function below.
int commonChild(const std::string &s1, const std::string &s2) {
	const int m = s1.size(), n = s2.size();

	std::vector<int> row(m + 1, 0);
	std::vector<std::vector<int>> grid(n + 1, row);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s1[i] == s2[j]) {
				grid[i + 1][j + 1] = grid[i][j] + 1;
			}
			else {
				grid[i + 1][j + 1] = std::max(grid[i + 1][j], grid[i][j + 1]);
			}
		}
	}
	return grid[m][n];
}