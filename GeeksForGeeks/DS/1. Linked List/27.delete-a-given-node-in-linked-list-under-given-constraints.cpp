// http://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/

#include<iostream>
#include "linkedList.h"
using namespace std;

void deleteNode(node *head, node *n){
	node *ptr = head;
	if(head == n){
		node *prev = head;
		while(ptr->next){
			ptr->data = ptr->next->data;
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		delete(ptr);
		return;
	}
	while(ptr->next != n){
		ptr = ptr->next;
	}
	ptr->next = n->next;
	delete(n);
}

int main(){
	node *head = NULL;
 
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List: ");
    printList(head);
 
    /* Let us delete the node with value 10 */
    printf("\nDeleting node %d: ", head->next->next->data);
    deleteNode(head, head->next->next);
 
    printf("\nModified Linked List: ");
    printList(head);
 
    /* Let us delete the the first node */
    printf("\nDeleting first node ");
    deleteNode(head, head);
 
    printf("\nModified Linked List: ");
    printList(head);
	return 0;
}

