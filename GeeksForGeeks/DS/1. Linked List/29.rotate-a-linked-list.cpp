// http://www.geeksforgeeks.org/rotate-a-linked-list

#include <iostream>
#include "linkedList.h"

void rotate(node **head, int k){
	node *ptr = *head;
	while(k>1){
		ptr = ptr->next;
		k--;
	}
	node *tmp = ptr->next;
	ptr->next = NULL;
	ptr = tmp;
	while(ptr->next){
		ptr = ptr->next;
	}
	ptr->next = *head;
	*head = tmp;
}

int main() {
	node* head = NULL;
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    rotate(&head, 4);
 
    printf("\nRotated Linked list \n");
    printList(head);
	return 0;
}

