#include <cstdint> // INTn_MIN, INTn_MAX
#include "Node.h"

bool checkBST(Node* root, int low = INT32_MIN, int high = INT32_MAX) {
	if (root == nullptr) {
		return true;
	}

	if (root->data <= low || root->data >= high) {
		return false;
	}

	if (!checkBST(root->left, low, root->data) ||
		!checkBST(root->right, root->data, high)) {
		return false;
	}

	return true;
}