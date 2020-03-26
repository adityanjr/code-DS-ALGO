// http://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions

#include <iostream>
#include "linkedList.h"

void merge(node *head1, node **head2){
	if(head1 == NULL)
 	    return;
	node *ptr1 = head1;
	while(ptr1 && *head2){
		node *tmp = (*head2)->next;
		(*head2)->next = ptr1->next;
		ptr1->next = (*head2);
		(*head2) = tmp;
		ptr1 = ptr1->next->next;
	}
}

int main(){
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);
 
     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);
 
     merge(p, &q);
 
     printf("Modified First Linked List:\n");
     printList(p);
 
     printf("Modified Second Linked List:\n");
     printList(q);
 
     getchar();
     return 0;
}
