// Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

// A Node is defined as:
struct Node {
	int data;
	struct Node* next;
};


bool has_cycle(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return false;
	}

	Node* slow = head;
	Node* fast = head->next->next;

	while (slow != fast) {
		if (fast == nullptr || fast->next == nullptr) {
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	return true;
}