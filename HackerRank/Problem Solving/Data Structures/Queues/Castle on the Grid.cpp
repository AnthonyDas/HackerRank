#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility> // std::make_pair
#include <unordered_set>
// #include <functional> // std::hash

int key(const std::pair<int, int> &pt) {
	// return std::hash<int>()(x) ^ std::hash<int>()(y);

	return (pt.first * 100) + pt.second; // Max n = 100
}

void move_in_dir(const std::vector<std::string> &grid, std::queue<std::pair<int, int> > &q, std::unordered_set<int> &visited,
	bool &dir_avail, const std::pair<int, int> &current, const int &x_offset, const int &y_offset) {

	if (dir_avail) {

		std::pair<int, int> pt(current.first + x_offset, current.second + y_offset);

		if (pt.first >= 0 && pt.first < grid.size() && pt.second >= 0 && pt.second < grid.size() &&
			grid[pt.first][pt.second] == '.') {

			if (visited.find(key(pt)) == visited.end()) {
				visited.insert(key(pt));
				q.push(pt);
			}
		}
		else {
			dir_avail = false;
		}
	}
}

// Complete the minimumMoves function below.
int minimumMoves(const std::vector<std::string> &grid, const int &startX, const int &startY,
	const int &goalX, const int &goalY) {

	const std::pair<int, int> start(startX, startY);

	std::queue<std::pair<int, int> > q;
	q.push(start);

	std::unordered_set<int> visited;
	visited.insert(key(start));

	int move_count = 0, remaining_in_level = q.size();
	while (!q.empty()) {
		std::pair<int, int> current = q.front();
		q.pop();

		// std::cout << move_count << " " << remaining_in_level << " " << current.first << " " << current.second << std::endl;

		// Have we reached the destination?
		if (current.first == goalX && current.second == goalY) {
			return move_count;
		}

		bool north = true, east = true, south = true, west = true;
		for (int i = 1; i < grid.size(); ++i) {
			move_in_dir(grid, q, visited, north, current, 0, -i);
			move_in_dir(grid, q, visited, east, current, i, 0);
			move_in_dir(grid, q, visited, south, current, 0, i);
			move_in_dir(grid, q, visited, west, current, -i, 0);
		}

		// Have we finished traversing at current depth?
		if (!(--remaining_in_level)) {
			remaining_in_level = q.size();
			++move_count;
		}
	}

	return -1;
}