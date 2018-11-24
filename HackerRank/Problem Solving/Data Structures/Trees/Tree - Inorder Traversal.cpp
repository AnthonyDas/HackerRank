#include <iostream>
#include "Node.h"

void inOrder(Node *root) {
	if (root == nullptr) { return; }

	inOrder(root->left);
	std::cout << root->data << " ";
	inOrder(root->right);
}