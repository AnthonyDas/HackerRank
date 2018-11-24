#include <algorithm> // max
#include "Node.h"

int getHeight(Node* root) {
	if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
		return 0;
	}

	return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}