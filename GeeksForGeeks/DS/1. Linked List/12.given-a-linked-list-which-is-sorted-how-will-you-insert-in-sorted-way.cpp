// http://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way

#include <iostream>
#include "linkedList.h"

void sortedInsert(node **head, int data){
	node *p = new node;
	p->data = data;
	p->next = NULL;
	if(*head == NULL){
		*head = p;
		return;
	}
	node *ptr = *head;
	node *prev = *head;
	while(ptr && ptr->data < data){
		prev = ptr;
		ptr = ptr->next;
	}
	if(ptr == *head){
		p->next = ptr;
		*head = p;
	}
	else {
		prev->next = p;
		p->next = ptr;
	}
}

int main(){

    /* Start with the empty list */
    node* head = NULL;
    sortedInsert(&head, 5);
    sortedInsert(&head, 10);
    sortedInsert(&head, 7);
    sortedInsert(&head, 3);
    sortedInsert(&head, 1);
    sortedInsert(&head, 9);
    printf("\n Created Linked List\n");
    printList(head);
 
    getchar();
    return 0;
}
