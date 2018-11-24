#include <iostream>
#include "Node.h"

void preOrder(Node *root) {
	if (root == nullptr) { return; }

	std::cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}