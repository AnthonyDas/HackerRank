#include <vector>
#include <unordered_set>
#include <stack>

void connected_graph_vertices(const std::vector<std::vector<bool>> &adj_matrix,
	const int &root_index, std::unordered_set<int> &connected) {

	connected.clear();
	connected.insert(root_index);

	std::stack<int> s({ root_index });

	while (!s.empty()) {
		auto &row = adj_matrix[s.top()];
		// Only need to examine to the right of matrix diagonal
		for (int i = (s.top() + 1); i < row.size(); ++i) {
			if (row[i] && connected.find(i) == connected.end()) {
				connected.insert(i);
				s.push(i);
			}
		}
		s.pop();
	}
}

/*n: integer, the number of cities
c_lib: integer, the cost to build a library
c_road: integer, the cost to repair a road
cities: 2D array of integers where each cities[i] contains two integers
that represent cities connected by an obstructed road. */
long roadsAndLibraries(const int &n, const int &c_lib, const int &c_road,
	const std::vector<std::vector<int>> &cities) {

	if (c_lib <= c_road) {
		return (long)n * c_lib;
	}

	// Adjacency Matrix
	std::vector<bool> row(n, false);
	std::vector<std::vector<bool>> adj_matrix(n, row);

	// Mark each city connected to itself for completeness
	/* for (int i = 0; i < n; ++i) {
		adj_matrix[i][i] = true;
	}*/

	// Read in roads data
	for (auto &c : cities) {
		const int i = c.front() - 1;
		const int j = c.back() - 1;

		adj_matrix[i][j] = adj_matrix[j][i] = true;
	}

	long cost = 0;

	std::vector<bool> visited(n, false); // Visited cities
	std::unordered_set<int> connected; // Connected cities

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			connected_graph_vertices(adj_matrix, i, connected);

			for (auto &j : connected) {
				visited[j] = true;
			}

			cost += c_lib + (connected.size() - 1) * c_road;
		}
	}

	return cost;
}
