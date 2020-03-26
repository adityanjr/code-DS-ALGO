// http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
// http://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/
/***/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node *random;
};

void append(Node **head, int data){
	Node *ptr = *head;
	Node *p = new Node;
	p->data = data;
	p->next = NULL;
	p->random = NULL;
	if(ptr == NULL){
		*head = p;
	}
	else {
		while(ptr->next){
			ptr = ptr->next;
		}
		ptr->next = p;
	}
}

void print(Node *head){
	Node *ptr = head;
	while(ptr){
		if(ptr->random)
			cout<<"Data: "<<ptr->data<<" "<<"Random ptr: "<<ptr->random->data<<'\n';
		else
			cout<<"Data: "<<ptr->data<<" "<<'\n';
		ptr = ptr->next;
	}
	cout<<'\n';
}

Node *makeClone(Node *head){
	if(head == NULL)
		return NULL;
	Node *ptr = head;
	while(ptr){
		Node *n = new Node;
		n->data = ptr->data;
		n->random = NULL;
		n->next = ptr->next;
		ptr->next = n;
		ptr = ptr->next->next;
	}
	ptr = head;
	// Set Random
	while(ptr){
		ptr->next->random = ptr->random->next;
		ptr = ptr->next->next;
	}
	Node *Head = head->next;
	ptr = head;
	Node *p = head->next;
	while(ptr){
		ptr->next = ptr->next->next;
		ptr = ptr->next;
		if(p->next)
			p->next = p->next->next;
		p = p->next;
	}
	return Head;
}

int main(){
	Node *head = NULL;
	for(int i=1; i<6; i++)
    	append(&head, i);

    // Setting up random references.
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;

    // Making a clone of the original linked list.
    Node *clone = makeClone(head);

    // Print the original and cloned linked list.
    print(head);
    print(clone);
	return 0;
}
