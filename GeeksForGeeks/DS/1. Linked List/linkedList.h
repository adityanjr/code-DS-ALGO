// Linkded List Header
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

void deleteNode(node **head, int data){
	node *ptr = *head;
	if((*head)->data == data){
		*head = (*head)->next;
		delete(ptr);
		return;
	}
	node *prev = *head;
	while(ptr->data != data){
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = ptr->next;
	delete(ptr);
}

// Insert after node
void insertAfterNode(node* head, int data){
	node* p = new node;
	p->data = data;
	p->next = head->next;
	head->next = p;
}

int getCountIteration(node *head){
	int count = 0;
	node *ptr = head;
	while(ptr){
		ptr = ptr->next;
		count++;
	}
	return count;
}

int getCountRecurtion(node *head){
	if(head == NULL)
			return 0;
	return 1+getCountRecurtion(head->next);
}

bool searchRec(node *head, int x){
	if(head == NULL)
			return -1;
	searchRec(head->next, x);
}

// Merge Sort
void divide(node *head, node **a, node **b){
	if(head == NULL)
		return;
	*a = head;
	node *prev = NULL;
	node *slow = head;
	node *fast = head;
	while(fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = NULL;
	*b = slow;
}

node* merge(node *a, node *b){
	if(a && b) {
		node *tmp, *t;
		if(a->data < b->data){
			tmp = a;
			t = merge(a->next, b);
		}
		else {
			tmp = b;
			t = merge(a, b->next);
		}
		tmp->next = t;
		return tmp;
	}
	else if(a) {
		return a;
	}
	else
		return b;
}

void mergeSort(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *a, *b;
	node *h = *head;
	divide(h, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head = merge(a, b);
}

