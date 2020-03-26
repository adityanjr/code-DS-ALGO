// http://www.geeksforgeeks.org/merge-sort-for-linked-list/
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

void mergeLinkedList(node **head, node **head2) {
	node *ptr;
	node *res;
	if((*head)->data < (*head2)->data) {
		ptr = *head;
		*head = (*head)->next;
	}
	else {
		ptr = *head2;
		*head2 = (*head2)->next;
	}
	res = ptr;
	while(*head && *head2) {
		if((*head)->data < (*head2)->data) {
			ptr->next = *head;
			*head = (*head)->next;
		}
		else {
			ptr->next = *head2;
			*head2 = (*head2)->next;
		}
		ptr = ptr->next;
	}
	if(*head)
		ptr->next = *head;
	else
		ptr->next = *head2;
	*head = res;
}

void mergeSortLinkedList(node **head) {
	if(*head == NULL || (*head)->next == NULL)
		return;
	node* slowptr = *head;
	node* fastptr = *head;
	node* ptr = *head;
 	while (fastptr) {
 		fastptr = fastptr->next;
 		if (fastptr) {
 			ptr = slowptr;
	 		slowptr = slowptr->next;
 			fastptr = fastptr->next;
 		}
 	}
 	ptr->next = NULL;
	mergeSortLinkedList(head);
	mergeSortLinkedList(&slowptr);
	mergeLinkedList(head, &slowptr);
}

int main(){
	int arr[] = {2, 1, 5, 12, 10, 11, 50, 10, 8, 0};
	node *head = createLinkedList(arr, sizeof(arr)/sizeof(arr[0]));
	mergeSortLinkedList(&head);
	printLinkedList(head);
}