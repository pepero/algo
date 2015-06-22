struct Node {
	int val;
	Node* next;
};

Node* selectSort(Node* head)
{
	Node* begin = NULL;
	Node* end = NULL;
	Node* curr = head;
	Node* minNode = NULL;
	int min = INT_MIN;
	while (curr){
    Node* node = curr;
		while (node) {
		 if (node->val < min) {
				minNode = node;
		 }



	}



}

