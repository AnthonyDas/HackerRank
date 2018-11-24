// The tree node has data, left child and right child
struct Node {
	int data;
	Node* left;
	Node* right;
};

// https://en.wikipedia.org/wiki/Lowest_common_ancestor
// Here "lowest" means "deepest" node
Node *lca(Node *root, int v1, int v2) {

	if (root->data < v1 && root->data < v2) {
		return lca(root->right, v1, v2);
	}
	else if (v1 < root->data && v2 < root->data) {
		return lca(root->left, v1, v2);
	}

	return root;
}