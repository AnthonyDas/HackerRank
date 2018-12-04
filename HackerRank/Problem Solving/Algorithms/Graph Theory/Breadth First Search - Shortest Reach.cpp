#include <vector>
#include <queue>
#include <unordered_set>

// SEE: HackerRank\HackerRank\Interview Preparation Kit\Graphs\BFS - Shortest Reach in a Graph.cpp

// Complete the bfs function below.
std::vector<int> bfs(const int &nodes, const int &m, const std::vector<std::vector<int> > &edges,
	const int &start, const int &step_size = 6) {

	std::vector<std::unordered_set<int> > adj_nodes(nodes);
	for (auto &edge : edges) {
		// Convert 1-indexed node names to 0-indexed vec position
		const int u = edge.front() - 1;
		const int v = edge.back() - 1;

		adj_nodes[u].insert(v);
		adj_nodes[v].insert(u);
	}

	std::vector<int> distances(nodes, -1);
	distances[start - 1] = 0; // Start has zero distance

	std::queue<int> nodes_visiting({ start - 1 }); // Current nodes visiting
	std::unordered_set<int> nodes_visited({ start - 1 }); // Visited nodes

	int steps = 0;

	// Based on Dijkstra's shortest path algorithm
	while (!nodes_visiting.empty()) {

		// For each node we are currently visiting, find the adjacent nodes
		int queue_size = (int)nodes_visiting.size();
		while (queue_size--) {
			const int &visiting = nodes_visiting.front();
			for (auto &next : adj_nodes[visiting]) {
				// If we have not previsouly visited next, add it to the queue
				if (nodes_visited.find(next) == nodes_visited.end()) {
					nodes_visiting.push(next);
					nodes_visited.insert(next);

					// Update the distances
					distances[next] = (steps + 1) * step_size;
				}
			}

			// Finished visiting front node
			nodes_visiting.pop();
		}

		++steps;
	}

	return distances;
}
