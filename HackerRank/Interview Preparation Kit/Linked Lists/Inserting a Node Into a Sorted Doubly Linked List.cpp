// For your reference:
class DoublyLinkedListNode {
	public:
		int data;
		DoublyLinkedListNode *next;
		DoublyLinkedListNode *prev;

		DoublyLinkedListNode(int node_data) {
			this->data = node_data;
			this->next = nullptr;
			this->prev = nullptr;
		}
};


// Complete the sortedInsert function below.
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
	DoublyLinkedListNode* inserted = new DoublyLinkedListNode(data);

	if (head == nullptr) {
		return inserted;
	}

	// Is this a new head?
	if (inserted->data <= head->data) {
		inserted->next = head;
		head->prev = inserted;

		return inserted;
	}

	DoublyLinkedListNode* node = head, *prv;
	while (node != nullptr && node->data < inserted->data) {
		prv = node;
		node = node->next;
	}

	// By now node is either nullptr or node->data greater than inserted->data
	if (node == nullptr) {
		// inserted is the new tail
		prv->next = inserted;
		inserted->prev = prv;
	}
	else {
		// inserted comes after node->prev
		node->prev->next = inserted;
		inserted->prev = node->prev;
		// inserted comes before node
		node->prev = inserted;
		inserted->next = node;
	}

	return head;
}