// http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

#include <iostream>
#include "linkedList.h"

node *reverse(node *head){
	if(head==NULL || head->next == NULL)
		return head;
	node *ptr = head->next;
	node *prev = head;
	head->next = NULL;
	while(ptr){
		node *tmp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = tmp;
	}
	return prev;
}

node *reverseK(node *head, int k){
	if(head == NULL || head->next == NULL)
		return head;
	node *ptr = head->next;
	int i=2;
	node *prev = head;
	node *H = NULL;
	node *tail = NULL;
	while(ptr){
		while(ptr && i<k){
			ptr = ptr->next;
			i++;
		}
		i=1;
		node *tmp = NULL;
		if(ptr){
			tmp = ptr->next;
			ptr->next = NULL;
		}
		ptr = tmp;
		node *rev = reverse(prev);
		prev = ptr;
		if(H == NULL){
			H = rev;
		}
		else {
			tail->next = rev;
		}
		while(rev->next)
			rev = rev->next;
		tail = rev;
	}
	tail->next = prev;
	return H;
}

int main(){
	node* head = NULL;

     /* Created Linked list is 1->2->3->4->5->6->7->8 */
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);

     printf("\n Given linked list \n");
     printList(head);
     head = reverseK(head, 3);

     printf("\n Reversed Linked list \n");
     printList(head);
	return 0;
}
