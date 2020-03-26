// http://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

#include <iostream>
#include  "linkedList.h"

void skipMdeleteN(node *head, int M, int N){
	node *ptr = head;
	node *prev = NULL;
	int skip = 0;
	while(skip<M){
		prev = ptr;
		ptr = ptr->next;
		skip++;
	}
	prev->next = NULL;
	skip=0;
	node *tmp = NULL;
	while(skip < N){
		tmp = ptr;
		ptr = ptr->next;
		delete(tmp);
		skip++;
	}
	prev->next = ptr;
	
}

int main(){
    /* Create following linked list
      1->2->3->4->5->6->7->8->9->10 */
    struct node* head = NULL;
    int M=2, N=3;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("M = %d, N = %d \nGiven Linked list is :\n", M, N);
    printList(head);
 
    skipMdeleteN(head, M, N);
 
    printf("\nLinked list after deletion is :\n");
    printList(head);
 
    return 0;
}
