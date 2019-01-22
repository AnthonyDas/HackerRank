#include <vector>
#include <algorithm> // sort
#include <unordered_set>

// Complete the prims function below.
// edges: a two-dimensional array where each element contains three integers,
// the two nodes that are connected and the weight of that edge.
int prims(const int &n, std::vector<std::vector<int> > edges, int start) {

	// Sort by weight ascending
	std::sort(edges.begin(), edges.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
		return a[2] < b[2]; }
	);

	int total_weight = 0;

	// To begin with, every node belongs to a (disjoint) set containing just itself
	std::vector<int> node_set_id(n); // Vector indicating which set a node belongs to
	std::vector<std::unordered_set<int> > node_sets(n); // Vector of node sets
	for (int i = 0; i < n; ++i) {
		node_set_id[i] = i;
		node_sets[i].insert(i);
	}

	// Now start adding in the edges, connecting up the (disjoint) sets.
	// Ultimately, we want all the nodes to be in a single set, (i.e. network is connected).
	for (auto &e : edges) {
		// -1 to convert 1-indexed nodes to 0-indexed
		const int node1 = e[0] - 1;
		const int node2 = e[1] - 1;

		// Only include edges that connect up two disjoint sets. Merge the sets.
		if (node_set_id[node1] != node_set_id[node2]) {
			total_weight += e[2];

			const int set_id1 = node_set_id[node1];
			const int set_id2 = node_set_id[node2];

			for (auto &node : node_sets[set_id2]) {
				node_sets[set_id1].insert(node);
				node_set_id[node] = set_id1;
			}
			node_sets[set_id2].clear();
		}
	}

	return total_weight;
}