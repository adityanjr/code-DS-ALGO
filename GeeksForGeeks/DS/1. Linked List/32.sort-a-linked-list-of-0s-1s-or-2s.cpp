// http://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/

#include <iostream>
#include "linkedList.h"
using namespace std;

void sortList(node **head){
	 node *head0 = NULL;
	 node *tail0 = NULL;
	 node *head1 = NULL;
	 node *tail1 = NULL;
	 node *head2 = NULL;
	 node *tail2 = NULL;
	 node *ptr = *head;
	 node *prev = NULL;
	 while(ptr){
	 	prev = ptr;
	 	ptr = ptr->next;
	 	prev->next = NULL;
	 	int d = prev->data;
	 	node *h, *t;
	 	if(d == 0){
	 		if(head0 == NULL)
			    head0 = prev;
 			else {
 				tail0->next = prev;
 			}
 			tail0 = prev;
	 	}
	 	else if(d == 1){
	 		if(head1 == NULL)
			    head1 = prev;
 			else {
 				tail1->next = prev;
 			}
 			tail1 = prev;
	 	}
	 	else {
	 		if(head2 == NULL)
			    head2 = prev;
 			else {
 				tail2->next = prev;
 			}
 			tail2 = prev;
	 	}
 	}
 	
 	
 	if(tail1){
	    tail1->next = head2;
	}
    if(tail0)
	    tail0->next = head1;
 
    if(head0){
	    *head = head0;
    }
    else if(head1){
    	*head = head1;
    }
 	else{
  	 	*head = head2;
 	}
}

int main(){
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    printf("Linked List Before Sorting\n");
    printList(head);
 
    sortList(&head);
 
    printf("Linked List After Sorting\n");
    printList(head);
 
    return 0;
}
