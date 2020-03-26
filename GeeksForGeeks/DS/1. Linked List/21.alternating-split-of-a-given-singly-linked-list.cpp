// http://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list

#include<iostream>
#include "linkedList.h"

void AlternatingSplit(node *head, node **a, node **b){
	if(head == NULL)
		return;
	node *ptr = head;
	node *head1 = NULL;
	node *head2 = NULL;
	bool tmp = true;
	while(ptr){
		if(tmp){
			append(&head1, ptr->data);
		}
		else{
			append(&head2, ptr->data);
		}
		tmp = !tmp;
		ptr = ptr->next;
	}
	*a = head1;
	*b = head2;
}

int main(){
	node* head = NULL;
	node* a = NULL;
	node* b = NULL;  
 
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 0->1->2->3->4->5 */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);                                    
  push(&head, 0);  
 
  printf("\n Original linked List:  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  AlternatingSplit(head, &a, &b); 
 
  printf("\n Resultant Linked List 'a' ");
  printList(a);            
 
  printf("\n Resultant Linked List 'b' ");
  printList(b);
	return 0;
}

