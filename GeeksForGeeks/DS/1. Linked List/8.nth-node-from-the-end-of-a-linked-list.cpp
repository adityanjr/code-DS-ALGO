// http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list

#include <iostream>
#include "linkedList.h"

void printNthFromLast(node *head, int N){
	node *slow = head;
	node *fast = head;
	while(N && fast){
		fast = fast->next;
		N--;
	}
	if(N != 0){
		cout<<"N > Length of list";
		return;
	}
	while(fast){
		slow = slow->next;
		fast = fast->next;
	}
	cout<<slow->data;
}

void recurse(node *head, int &N){
	if(head == NULL)
		return;
	recurse(head->next, N);
	N--;
	if(N==0)
		cout<<head->data;
}

int main(){
  /* Start with the empty list */
  node* head = NULL;
 
  // create linked 35->15->4->20
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);
 
  //printNthFromLast(head, 5);
  int n = 4;
  recurse(head, n);
  return 0; 
}
