// http://www.geeksforgeeks.org/write-a-recursive-function-to-print-reverse-of-a-linked-list/

#include <iostream>
#include "linkedList.h"

void printReverse(node *head) {
	if(head == NULL)
		return;
	printReverse(head->next);
	cout<<head->data<<" ";
}

int main(){
	node* head = NULL; 
	push(&head, 1);
  	push(&head, 2);
  	push(&head, 3);
  	push(&head, 4);
  	printList(head);
  	printReverse(head);
	return 0;
}

