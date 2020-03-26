// http://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list

#include <iostream>
#include "linkedList.h"

void deleteList(node **head){
	if((*head) == NULL)
		return;
	node *tmp = *head;
	*head = (*head)->next;
	delete(tmp);
	deleteList(head);
}

int main(){
    /* Start with the empty list */
    struct node* head = NULL;
    
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1); 
    push(&head, 12);
    push(&head, 1);   
    
    printf("\n Deleting linked list");
    deleteList(&head);  
    
    printf("\n Linked list deleted");
}
