// http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists
// one's as head

#include <iostream>
#include "linkedList.h"

node* addCarryToList(node *head, int &carry){
	if(head ==NULL && carry == 0)
		return NULL;
	node *ptr = new node;
	ptr->next = NULL;
	if(head == NULL){
		ptr->data = carry;
		return ptr;
	}
	ptr->data = (head->data + carry)%10;
	carry = (head->data + carry)/10;
	node *tmp = addCarryToList(head->next, carry);
	ptr->next = tmp;
	return ptr;
}

node* addTwoList(node *head1, node *head2, int &carry){
	if(head1 == NULL && head2 == NULL)
		return NULL;
	
	node *head = NULL;
	node *ptr1 = head1;
	node *ptr2 = head2;
	node *ptr;
	while(ptr1 && ptr2){
		node *p = new node;
		int data = ptr1->data + ptr2->data + carry;
		carry = data/10;
		p->data = data%10;
		p->next = NULL;
		if(head == NULL)
			head = p;
		else {
			ptr->next = p;
		}
		ptr = p;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if(ptr1 == NULL){
		ptr = addCarryToList(ptr2, carry);
	}
	else if(ptr2 == NULL){
		ptr = addCarryToList(ptr1, carry);
	}
	if(head){
		head->next = ptr;
	}
	else {
		head = ptr;
	}
	return head;
}

int main(){
	node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    int carry =0;
    res = addTwoList(first, second, carry);
    printf("Resultant list is ");
    printList(res);
	return 0;
}

