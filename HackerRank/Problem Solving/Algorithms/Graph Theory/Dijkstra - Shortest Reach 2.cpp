#include <vector>
#include <set>
#include <utility> // make_pair
#include <numeric> // accumulate 
#include <algorithm> // replace

/* Given an undirected graph and a starting node, determine the lengths of the
shortest paths from the starting node to all other nodes in the graph. If a node
is unreachable, its distance is -1. Nodes will be numbered consecutively from
1 to n, and edges will have varying distances or lengths. */

// Complete the shortestReach function below.
std::vector<int> shortestReach(const int &nodes, const std::vector<std::vector<int> > &edges, const int &start) {
	std::vector<std::set<std::pair<int, int> > > adj_nodes(nodes); // adjacent node, length
	for (auto &edge : edges) {
		// Convert 1-indexed node names to 0-indexed vec position
		const int start = edge[0] - 1;
		const int end = edge[1] - 1;
		const int length = edge[2];

		adj_nodes[start].insert(std::make_pair(end, length));
		adj_nodes[end].insert(std::make_pair(start, length));
	}

	std::vector<int> distances(nodes, INT32_MAX);
	distances[start - 1] = 0; // Start has zero distance

	std::vector<bool> nodes_visited(nodes, false);

	// Based on Dijkstra's shortest path algorithm
	while (std::accumulate(nodes_visited.begin(), nodes_visited.end(), 0) != nodes) {
		int visiting = -1;
		for (int i = 0; i < nodes; ++i) {
			if (!nodes_visited[i] && (visiting == -1 || distances[i] < distances[visiting])) {
				visiting = i;
			}
		}

		// If the shortest distance of the remaining unvisted nodes is INT32_MAX
		// it means there are no available paths to the remaining nodes. I.e.
		// they are not connected.
		if (distances[visiting] == INT32_MAX) {
			break;
		}

		// For the node we are currently visiting, find the adjacent nodes
		for (auto &next : adj_nodes[visiting]) {
			// If we have not previously visited next, update its distance if shorter
			if (!nodes_visited[next.first] &&
				(distances[visiting] + next.second < distances[next.first])) {

				// total distance = (distance to visiting) + (length between visiting and next)
				distances[next.first] = distances[visiting] + next.second;
			}
		}

		// Finished visiting node
		nodes_visited[visiting] = true;
	}

	// Replace INT32_MAX with -1
	std::replace(distances.begin(), distances.end(), INT32_MAX, -1);

	return distances;
}