#include <iostream>
#include <vector>
#include <queue>
#include <functional> // std::greater
#include <unordered_map>

int main() {
	int Q;
	std::cin >> Q;

	std::priority_queue<int, std::vector<int>, std::greater<int> > pq; // min heap
	std::unordered_map<int, int> to_delete;

	while (Q--) {
		int type;
		std::cin >> type;

		switch (type) {
			int v;

		case 1:
			// 1 v - Add an element v to the heap.
			std::cin >> v;
			pq.push(v);
			break;
		case 2:
			// 2 v - Delete the element v from the heap.
			std::cin >> v;
			++to_delete[v];
			break;
		case 3:
			// 3 - Print the minimum of all the elements in the heap.
			int min = pq.top();
			auto it = to_delete.find(min);
			while (it != to_delete.end()) {
				if (!(--it->second)) {
					to_delete.erase(it);
				}

				pq.pop();
				min = pq.top();
				it = to_delete.find(min);
			}

			std::cout << min << std::endl;
			break;
		}
	}

	return 0;
}