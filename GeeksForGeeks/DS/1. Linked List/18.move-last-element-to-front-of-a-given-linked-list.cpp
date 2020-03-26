// http://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list

#include <iostream>
#include "linkedList.h"
using namespace std;

void moveToFront(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *prev = *head;
	node *ptr = (*head)->next;
	while(ptr->next) {
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	ptr->next = *head;
	*head = ptr;
}

int main(){
	node *start = NULL;   
 
  /* The constructed linked list is:
   1->2->3->4->5 */
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);
 
  printf("\n Linked list before moving last to front ");
  printList(start);
 
  moveToFront(&start);
 
  printf("\n Linked list after removing last to front ");
  printList(start);
	return 0;
}

