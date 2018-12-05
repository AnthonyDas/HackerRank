#include <vector>
#include <queue>
#include <unordered_set>

/* Rules The game is played with a cubic die of 6 faces numbered 1 to 6.
- Starting from square 1, land on square 100 with the exact roll of the die.
If moving the number rolled would place the player beyond square 100, no mov
is made.
- If a player lands at the base of a ladder, the player must climb the ladder.
Ladders go up only.
- If a player lands at the mouth of a snake, the player must go down the
snake and come out through the tail. Snakes go down only. */


// Breadth first search
int shortest_reach(const std::vector<std::unordered_set<int> > &adj_nodes, const int &start, const int &end) {
	std::queue<int> nodes_visiting({ start }); // Current nodes visiting
	std::unordered_set<int> nodes_visited({ start }); // Visited nodes

	int steps = 0;

	// Based on Dijkstra's shortest path algorithm
	while (!nodes_visiting.empty()) {

		// For each node we are currently visiting, find the adjacent nodes
		int queue_size = (int)nodes_visiting.size();
		while (queue_size--) {
			const int &visiting = nodes_visiting.front();
			for (auto &next : adj_nodes[visiting]) {
				// If we have not previously visited next, add it to the queue
				if (nodes_visited.find(next) == nodes_visited.end()) {
					nodes_visiting.push(next);
					nodes_visited.insert(next);

					// Have we reached the end?
					if (next == end) {
						return ++steps;
					}
				}
			}

			// Finished visiting front node
			nodes_visiting.pop();	
		}

		++steps;
	}

	// Impossible - have explored every path and not reached the end
	return -1;
}


// Complete the quickestWayUp function below.
int quickestWayUp(const std::vector<std::vector<int> > &ladders, const std::vector<std::vector<int> > &snakes) {

	std::vector<std::unordered_set<int> > adj_nodes(99); // Board positions 1 to 99
	for (int pos = 0; pos < 99; ++pos) {
		for (int roll = 1; roll <= 6; ++roll) {
			if (pos + roll <= 99) {
				adj_nodes[pos].insert(pos + roll);
			}
			else {
				break;
			}
		}
	}

	for (auto &ladder : ladders) {
		// Convert 1-indexed node names to 0-indexed vec position
		const int start = ladder.front() - 1;
		const int end = ladder.back() - 1;

		for (auto &set : adj_nodes) {
			if (set.find(start) != set.end()) {
				set.erase(start);
				set.insert(end);
			}
		}
	}

	for (auto &snake : snakes) {
		// Convert 1-indexed node names to 0-indexed vec position
		const int start = snake.front() - 1;
		const int end = snake.back() - 1;

		for (auto &set : adj_nodes) {
			if (set.find(start) != set.end()) {
				set.erase(start);
				set.insert(end);
			}
		}
	}

	return shortest_reach(adj_nodes, 0, 99);
}