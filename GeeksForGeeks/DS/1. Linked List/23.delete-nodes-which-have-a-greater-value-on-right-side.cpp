// http://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side

#include <iostream>
#include <climits>
#include "linkedList.h"

node* delLesserNodes(node **head, int &max){
	if(*head == NULL || (*head)->next == NULL){
		if(*head) {
			if(max < (*head)->data)
				max = (*head)->data;
		}
		return *head;
	}
	node *tmp = delLesserNodes(&((*head)->next), max);
	if((*head)->data < max){
		node *ptr = tmp;
		delete(*head);
		return ptr;
	}
	else {
		max = (*head)->data;
		(*head)->next = tmp;
		return *head;
	}
}
 
int main(){
	node *head = NULL;
 
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,13);
    push(&head,12);
    push(&head,6);
    push(&head,5);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,0);
 
    printf("Given Linked List: ");
    printList(head);
 
    int max = INT_MIN;
    head = delLesserNodes(&head, max);
 
    printf("\nModified Linked List: ");
    printList(head);
	return 0;
}

