// http://geeksquiz.com/linked-list-set-2-inserting-a-node/

#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void append(node **head, int data){
	node *ptr = *head;
	node *p = new node;
	p->data = data;
	p->next = NULL;
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

void push(node **head, int data){
	node *p = new node;
	p->data = data;
	p->next = *head;
	*head = p;
}

void printList(node *head){
	node *ptr = head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<'\n';
}

void insertAfter(node* head, int data){
	node* p = new node;
	p->data = data;
	p->next = head->next;
	head->next = p;
}

int main() {
	struct node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);
 
  printf("\n Created Linked list is: ");
  printList(head);
  return 0;
}
