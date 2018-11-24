#include "Node.h"

Node * insert(Node * root, int data) {
	Node * n = new Node(data);

	if (root == nullptr) {
		return new Node(data);
	}
	else if (root->data < data) {
		root->right = insert(root->right, data);
	}
	else { // (root->data > data) 
		root->left = insert(root->left, data);
	}

	return root;
}