#include <algorithm> // max

// The tree node has data, left child and right child
struct Node {
	int data;
	Node* left;
	Node* right;
};

int height(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	return ((root->left != nullptr || root->right != nullptr) ? 1 : 0)
		+ std::max(height(root->left), height(root->right));
}