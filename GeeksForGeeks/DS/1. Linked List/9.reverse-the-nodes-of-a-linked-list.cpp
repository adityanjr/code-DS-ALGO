// http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/

#include <iostream>
#include "linkedList.h"

void reverse(node **head){
	if((*head) == NULL || (*head)->next == NULL)
		return;
	node *first, *second, *third;
	first = (*head);
	second = (*head)->next;
	third = second->next;
	first->next = NULL;
	while(second && third){
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	second->next = first;
	*head = second;
}

void recurse(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *first = *head;
	node *tmp = first->next;
	node *rest = first->next;
	
	recurse(&rest);
	tmp->next = first;
	first->next = NULL;
	*head = rest;
}

node *reverse1(node *head, node *prev){
	if(head == NULL)
		return NULL;
	if(head->next == NULL){
		head->next = prev;
		return head;
	}
	node *nextHead = head->next;
	node *nextPrev = head;
	head->next = prev;
	return reverse(nextHead, nextPrev);
}

int main() {
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printList(head);
     //reverse(&head);                      
     recurse(&head);
     printf("\n Reversed Linked list \n");
     printList(head);    
     getchar();
}
