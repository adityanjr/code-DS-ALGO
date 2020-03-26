// http://geeksquiz.com/find-length-of-a-linked-list-iterative-and-recursive

#include "linkedList.h"

int getCountIter(node *head){
	int count = 0;
	node *ptr = head;
	while(ptr){
		ptr = ptr->next;
		count++;
	}
	return count;
}

int getCountRec(node *head){
	if(head == NULL)
			return 0;
	return 1+getCountRec(head->next);
}

int main(){
	node* head = NULL;
 
    /* Use push() to construct below list
     1->2->1->3->1  */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    /* Check the count function */
    printf("count of nodes is %d", getCountRec(head));
    return 0;
}
