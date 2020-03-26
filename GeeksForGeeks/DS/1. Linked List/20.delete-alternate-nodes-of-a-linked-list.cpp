// http://www.geeksforgeeks.org/delete-alternate-nodes-of-a-linked-list

#include<iostream>
#include "linkedList.h"

void deleteAlt(node *head){
	if(head == NULL || head->next == NULL)
		return;
	node *prev = head;
	node *ptr = head->next;
	prev->next = ptr->next;
	delete(ptr);
	deleteAlt(prev->next);
}

int main(){
	int arr[100];  
 
  /* Start with the empty list */
  struct node* head = NULL;
 
  /* Using push() to construct below list
    1->2->3->4->5  */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2); 
  push(&head, 1);    
 
  printf("\n List before calling deleteAlt() ");
  printList(head);
 
  deleteAlt(head);
 
  printf("\n List after calling deleteAlt() ");
  printList(head);
	return 0;
}

