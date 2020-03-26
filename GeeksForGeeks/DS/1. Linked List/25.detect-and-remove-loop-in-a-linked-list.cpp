// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include <iostream>
#include "linkedList.h"

void detectAndRemoveLoop(node *head){
	if(head == NULL || head->next == NULL)
		return;
	node *slow = head;
	node *fast = head;
	node *prev = NULL;
	while(slow && fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(fast == NULL || fast->next == NULL){
		cout<<"No-loop";
		return;
	}
	fast = head;
	
	while(slow != fast) {
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	prev->next = NULL;
}

int main(){
	node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
	return 0;
}

