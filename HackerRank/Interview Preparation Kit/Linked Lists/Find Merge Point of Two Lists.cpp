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


// Complete the findMergeNode function below.
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	SinglyLinkedListNode* node1 = head1, *node2 = head2;

	while (node1 != node2) {
		if (node1->next == nullptr) {
			node1 = head2;
		}
		else {
			node1 = node1->next;
		}

		if (node2->next == nullptr) {
			node2 = head1;
		}
		else {
			node2 = node2->next;
		}
	}

	return node1->data;
}