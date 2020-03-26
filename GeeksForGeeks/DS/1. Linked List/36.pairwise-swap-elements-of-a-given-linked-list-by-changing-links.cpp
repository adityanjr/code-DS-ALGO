// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links

#include <iostream>
#include "linkedList.h"

void pairWiseSwap(node **head){
	if(*head == NULL && (*head)->next)
 	    return;
	node *prev = NULL;
	node *cur = *head;
	node *next = (*head)->next;
	cur->next = next->next;
	next->next = cur;
	*head = next;
	while(cur->next && cur->next->next){
		prev = cur;
		cur = prev->next;
		next = cur->next;
		
		prev->next = cur->next;
		cur->next = next->next;
		next->next = cur;
	}
}

int main(){
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    pairWiseSwap(&start);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
    return 0;
}
