#include <iostream>
#include "Node.h"

void postOrder(Node *root) {
	if (root == nullptr) { return; }

	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->data << " ";
}