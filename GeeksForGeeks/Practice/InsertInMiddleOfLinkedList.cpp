/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the Node of the linked list is as
struct Node {
	int data;
	Node* next;
};
*/
// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	Node* middle = head, *end = head, *prev = NULL;
	
	while(end && end->next){
        prev = middle;
	    middle = middle->next;
	    end = (end->next)->next;
	}
	
	Node* XNode = new Node();
	XNode->data = x;
	
	if(!end){
	    // even length list
	    XNode->next = middle;
	    prev->next = XNode;
	}
	else{
	    // odd length
	    XNode->next = middle->next;
	    middle->next = XNode;
	}
	
	return head;
}
