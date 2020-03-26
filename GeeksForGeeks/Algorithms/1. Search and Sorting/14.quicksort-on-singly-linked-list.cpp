// http://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};


node* createLinkedList(int *arr, int n) {
	node *head = new node;
	head->data = arr[0];
	head->next = NULL;
	node *ptr = head;
	for (int i = 1; i < n; ++i) {
		node *p = new node;
		p->data = arr[i];
		p->next = NULL;
		ptr->next = p;
		ptr = ptr->next;
	}
	return head;
}

void printLinkedList(node *head) {
	node *ptr = head;
	while(ptr) {
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<'\n';
}

node* linkedListPartition(node **head) {
	if ((*head) == NULL | (*head)->next == NULL)
		return NULL;
	node *ptr = (*head)->next;
	node *piv = (*head);
	node *j = *head;
	node *tmp2;
	while(ptr) {
		if(ptr->data < piv->data) {
			tmp2 = ptr->next;
			j->next = ptr->next;
			ptr->next = *head;
			*head = ptr;
			ptr = tmp2;
		}
		else {
			j = j->next;
			ptr = ptr->next;
		}
	}
	return piv;
}

void linkedListQuickSort(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *piv = linkedListPartition(head);
	if(piv == NULL)
		return;
	node *ptr = *head;
	linkedListQuickSort(&(piv->next));
	node *tmp = piv->next;
	piv->next = NULL;
	linkedListQuickSort(head);
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	return;
}

int main(){
	int arr[] = {4, 2, 0, 0, 1, 0, 0, 0};
	int n = sizeof(arr)/sizeof(*arr);
	node *head = createLinkedList(arr, n);
	linkedListQuickSort(&head);
	printLinkedList(head);
	return 0;
}