#include <string>
#include <iostream>


// The structure of the node is
struct node {
	int freq;
	char data;
	node * left;
	node * right;

};


void decode_huff(node * root, const std::string &s) {
	std::string res;
	
	node * ptr = root;

	for (auto &c : s) {
		if (c == '0') {
			ptr = ptr->left;
		}
		else { // c == '1'
			ptr = ptr->right;
		}

		if (ptr->data != '\0') {
			res.push_back(ptr->data);
			ptr = root;
		}
	}

	std::cout << res << std::endl;
}