#include <vector>
#include <queue>
#include <unordered_set>

class Graph {

	const int nodes;

	std::vector<std::unordered_set<int> > adj_nodes;

public:

	Graph(const int &n) : nodes(n), adj_nodes(n) {}

	void add_edge(const int &u, const int &v) {
		adj_nodes[u].insert(v);
		adj_nodes[v].insert(u);
	}

	// Breadth first search
	std::vector<int> shortest_reach(const int &start, const int &step_size = 6) {
		std::vector<int> distances(nodes, -1);
		distances[start] = 0; // Start has zero distance

		std::queue<int> nodes_visiting({ start }); // Current nodes visiting

		int steps = 0;

		// Based on Dijkstra's shortest path algorithm
		while (!nodes_visiting.empty()) {

			// For each node we are currently visiting, find the adjacent nodes
			int queue_size = (int)nodes_visiting.size();
			while (queue_size--) {
				const int &visiting = nodes_visiting.front();
				for (auto &next : adj_nodes[visiting]) {
					// If we have not previously visited next, add it to the queue
					if (distances[next] == -1) {
						nodes_visiting.push(next);

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

};
