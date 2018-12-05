#include <vector>
#include <queue>
#include <unordered_set>

int findShortest(const int &graph_nodes, const std::vector<int> &graph_from,
	const std::vector<int> &graph_to, const std::vector<int> &ids, const int &target_id) {

	// Adjacency nodes
	std::vector<std::unordered_set<int> > adj_nodes(graph_nodes);

	for (int i = 0; i < graph_from.size(); ++i) {
		const int from = graph_from[i] - 1;
		const int to = graph_to[i] - 1;

		adj_nodes[to].insert(from);
		adj_nodes[from].insert(to);
	}

	// Perform multiple concurrent Dijkstra’s Shortest Path Algorithms
	// starting at all nodes with the targer id.

	// We don't need to run any Dijkstra’s to completion, because we can
	// return as soon as one finds a path between two nodes with target id.

	std::vector<std::queue<int> > nodes_visiting; // Current nodes visiting
	std::vector<std::unordered_set<int> > nodes_visited; // Visited nodes

	// Find the nodes with the target id
	for (int i = 0; i < ids.size(); ++i) {
		if (ids[i] == target_id) {
			nodes_visiting.emplace_back(std::queue<int>({ i }));
			nodes_visited.emplace_back(std::unordered_set<int>({ i }));
		}
	}

	// Must be at least two nodes with the target id
	if (nodes_visiting.size() < 2) {
		return -1;
	}

	int steps = 0;

	bool finished = false;
	while (!finished) {
		finished = true;

		for (int i = 0; i < nodes_visiting.size(); ++i) { // For each Dijkstra

			// For each node we are currently visiting, find the adjacent nodes
			int queue_size = (int)nodes_visiting[i].size();
			while (queue_size--) {
				const int &visiting = nodes_visiting[i].front();
				for (auto &next : adj_nodes[visiting]) {
					// If we have not previously visited next, add it to the queue
					if (nodes_visited[i].find(next) == nodes_visited[i].end()) {
						nodes_visiting[i].push(next);
						nodes_visited[i].insert(next);

						finished = false;

						// If the next node has target id, then we have found the shorted path
						if (ids[next] == target_id) {
							return ++steps;
						}
					}
				}

				// Finished visiting front node
				nodes_visiting[i].pop();
			}
		}

		++steps;
	}

	// Could not find a path
	return -1;
}