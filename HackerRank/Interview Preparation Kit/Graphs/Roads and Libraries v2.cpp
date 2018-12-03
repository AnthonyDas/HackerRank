#include <vector>
#include <unordered_set>

/*n: integer, the number of cities
c_lib: integer, the cost to build a library
c_road: integer, the cost to repair a road
cities: 2D array of integers where each cities[i] contains two integers
that represent cities connected by an obstructed road. */
long roadsAndLibraries_v2(const int &n, const int &c_lib, const int &c_road,
	const std::vector<std::vector<int>> &cities) {

	if (c_lib <= c_road) {
		return (long)n * c_lib;
	}

	// Visited cities - index within disjoint_sets
	std::vector<int> visited(n, -1);
	std::vector<std::unordered_set<int> > disjoint_sets;

	for (auto &c : cities) {
		const int i = c.front() - 1;
		const int j = c.back() - 1;

		if (visited[i] == -1 && visited[j] == -1) {
			visited[i] = visited[j] = disjoint_sets.size();
			disjoint_sets.emplace_back(std::unordered_set<int>({ i, j }));
		}
		else if (visited[i] != -1 && visited[j] == -1) {
			visited[j] = visited[i];
			disjoint_sets[visited[i]].insert(j);
		}
		else if (visited[i] == -1 && visited[j] != -1) {
			visited[i] = visited[j];
			disjoint_sets[visited[j]].insert(i);
		}
		else { // visited[i] != -1 && visited[j] != -1

			/* if (visited[i] == visited[j]) {
				// Do nothing - both already seen and in the same set
			}*/
			if (visited[i] != visited[j]) {
				// Need to merge sets together - move j into i
				const int jth = visited[j];
				for (auto &e : disjoint_sets[jth]) {
					disjoint_sets[visited[i]].insert(e);
					visited[e] = visited[i];
				}
				disjoint_sets[jth].clear();
			}
		}
	}

	long cost = 0;

	// Add cost of connected cities
	for (auto &e : disjoint_sets) {
		if (!e.empty()) {
			cost += c_lib + (e.size() - 1) * c_road;
		}
	}
	// Include cities which are on their own
	for (auto &e : visited) {
		if (e == -1) {
			cost += c_lib;
		}
	}

	return cost;
}