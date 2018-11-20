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


// Complete the reverse function below.
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}

	DoublyLinkedListNode* res;
	while (head != nullptr) {
		DoublyLinkedListNode* temp = head->prev;

		head->prev = head->next;
		head->next = temp;

		res = head;

		head = head->prev;
	}

	return res;
}