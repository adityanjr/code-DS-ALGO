// http://www.geeksforgeeks.org/merge-sort-for-linked-list/

#include <iostream>
#include "linkedList.h"

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

void MergeSort(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *a, *b;
	node *h = *head;
	divide(h, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = merge(a, b);
}

int main() {
  	node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 10);
  push(&a, 15);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  MergeSort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);
	return 0;
}

