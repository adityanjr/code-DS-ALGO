// http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list

#include <iostream>
#include "linkedList.h"

void printMiddle(node *head) {
	node *slow = head;
	node *fast = head;
	if(head == NULL)
		return;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<slow->data;
}

int main() {
    /* Start with the empty list */
    struct node* head = NULL;
    int i;
 
    for (i=5; i>0; i--)
    {
        push(&head, i);
        printList(head);
    }
    printMiddle(head);
 
    return 0;
}
