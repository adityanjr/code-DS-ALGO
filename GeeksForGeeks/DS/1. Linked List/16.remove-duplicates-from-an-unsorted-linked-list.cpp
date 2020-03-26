// http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list
#include<iostream>
#include<map>
#include "linkedList.h"

void removeDuplicates(node *head) {
	if(head==NULL)
		return;
	map<int, bool> Map;
	node *ptr = head->next;
	node *prev = head;
	Map[head->data] = 1;
	while(ptr){
		if(Map.count(ptr->data) > 0) {
			prev->next = ptr->next;
			delete(ptr);
			ptr = prev->next;
		}
		else {
			Map[ptr->data] = 1;
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

int main(){
	node *start = NULL;
 
  /* The constructed linked list is:
   10->12->11->11->12->11->10*/
  push(&start, 10);
  push(&start, 11);
  push(&start, 12);
  push(&start, 11);
  push(&start, 11);
  push(&start, 12);
  push(&start, 10);
 
  printf("\n Linked list before removing duplicates ");
  printList(start);
 
  removeDuplicates(start);
 
  printf("\n Linked list after removing duplicates ");
  printList(start);
	return 0;
}

