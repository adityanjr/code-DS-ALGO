// http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list

#include<iostream>
#include <climits>
#include "linkedList.h"
using namespace std;

void removeDuplicates(node* head){
	if(head == NULL)
		return;
	node *prev = head;
	node *ptr = head->next;
	while(ptr) {
		if(ptr->data == prev->data){
			prev->next = ptr->next;
			delete(ptr);
			ptr = prev->next;			
		}
		else{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

int main(){
	struct node* head = NULL;
   
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 11->11->11->13->13->20 */
  push(&head, 20);
  push(&head, 20);
  push(&head, 13);
  push(&head, 13);  
  push(&head, 11);
  push(&head, 11);
  push(&head, 11);                                    
 
  printf("\n Linked list before duplicate removal  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  removeDuplicates(head); 
 
  printf("\n Linked list after duplicate removal ");         
  printList(head);
	return 0;
}

