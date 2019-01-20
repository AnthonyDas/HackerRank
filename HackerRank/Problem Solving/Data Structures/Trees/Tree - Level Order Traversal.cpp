#include <iostream>
#include <queue>
#include "Node.h"

// Breadth first search
void levelOrder(Node * root) {
	if (root == nullptr) {
		return;
	}

	std::queue<Node *> q({ root });

	while (!q.empty()) {
		// Print front current value
		std::cout << q.front()->data << " ";

		// Add children to the queue
		if (q.front()->left) {
			q.push(q.front()->left);
		}
		if (q.front()->right) {
			q.push(q.front()->right);
		}

		// Front fully processed - remove
		q.pop();
	}
}