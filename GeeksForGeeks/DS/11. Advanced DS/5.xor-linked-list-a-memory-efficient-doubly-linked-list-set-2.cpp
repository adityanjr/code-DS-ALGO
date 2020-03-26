// http://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ui;

struct node {
	int data;
	node *npx;
};

node* XOR(node *a, node *b){
	return (node*)((ui)(a) ^ (ui)(b));
}

void insert(node **head, int data){
	node *p = new node;
	p->data = data;
	p->npx = NULL;
	if(*head == NULL){
		*head = p;
		return;
	}
	node *ptr = *head;
	if(ptr->npx == NULL){
		ptr->npx = XOR(p, NULL);
		p->npx = XOR(ptr, NULL);
		return;
	}
	node *prev = NULL;
	node *x = XOR(ptr->npx, prev);
	while(x){
		prev = ptr;
		ptr = x;
		x = XOR(ptr->npx, prev);
	}
	ptr->npx = XOR(ptr->npx, p);
	p->npx = XOR(ptr, NULL);
}

void printList(node *head){
	node *ptr = head;
	node *prev = NULL;
	cout<<head->data<<" ";
	node *x = XOR(ptr->npx, prev);
	while(x){
		cout<<x->data<<" ";
		prev = ptr;
		ptr = x;
		x = XOR(ptr->npx, prev);
	}
}

int main(){
	/* Create following Doubly Linked List
       head-->40<-->30<-->20<-->10   */
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // print the created list
    printList (head);
	return 0;
}

