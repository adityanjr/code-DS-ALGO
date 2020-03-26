// http://www.geeksforgeeks.org/write-a-c-function-to-detect-loop-in-a-linked-list/

#include <iostream>
#include "linkedList.h"

void detectloop(node *head){
	node *slow = head;
	node *fast = head->next;
	while(fast && fast->next){
		if(fast == slow){
			cout<<"cycle";
			return;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<"no-cycle";
}

int main(){
  /* Start with the empty list */
  struct node* head = NULL;
 
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
 
  /* Create a loop for testing */
  head->next->next->next->next = head;
  detectloop(head);
 
  getchar();
}
