// For your reference:
class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};


// Complete the insertNodeAtPosition function below.
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

	if (head == nullptr) {
		return node;
	}

	SinglyLinkedListNode* prior = head;
	for (int i = 1; i <= position - 1; ++i) {
		prior = prior->next;
	}

	SinglyLinkedListNode* post = prior->next;
	prior->next = node;
	node->next = post;

	return head;
}