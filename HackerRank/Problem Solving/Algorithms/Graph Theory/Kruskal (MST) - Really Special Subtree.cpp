#include <vector>
#include <algorithm> // sort
#include <unordered_set>

/* Given an undirected weighted connected graph, find the Really Special SubTree in it.
The Really Special SubTree is defined as a subgraph consisting of all the nodes in the
graph and:

- There is only one exclusive path from a node to every other node.
- The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
- No cycles are formed.

To create the Really Special SubTree, always pick the edge with smallest weight.
Determine if including it will create a cycle. If so, ignore the edge. If there
are edges of equal weight available:

- Choose the edge that minimizes the sum u + v + wt where u and v are vertices and wt is
the edge weight.
- If there is still a collision, choose any of them.

Print the overall weight of the tree formed using the rules. */
int kruskals(const int &g_nodes, const std::vector<int> &g_from, const std::vector<int> &g_to,
	const std::vector<int> &g_weight) {

	std::vector<std::vector<int> > edges;
	for (int i = 0; i < g_weight.size(); ++i) {
		// -1 to convert 1-indexed nodes to 0-indexed
		edges.push_back(std::vector<int>({ (g_from[i] - 1), (g_to[i] - 1), g_weight[i] }));
	}

	// Sort by weight ascending
	std::sort(edges.begin(), edges.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
		if (a[2] != b[2]) {
			return a[2] < b[2];
		}
		return (a[0] + a[1] + a[2]) < (b[0] + b[1] + b[2]);
		}
	);

	int total_weight = 0;

	// To begin with, every node belongs to a (disjoint) set containing just itself
	std::vector<int> node_set_id(g_nodes); // Vector indicating which set a node belongs to
	std::vector<std::unordered_set<int> > node_sets(g_nodes); // Vector of node sets
	for (int i = 0; i < g_nodes; ++i) {
		node_set_id[i] = i;
		node_sets[i].insert(i);
	}

	// Now start adding in the edges, connecting up the (disjoint) sets.
	// Ultimately, we want all the nodes to be in a single set, (i.e. network is connected).
	for (auto &e : edges) {
		const int node1 = e[0];
		const int node2 = e[1];

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