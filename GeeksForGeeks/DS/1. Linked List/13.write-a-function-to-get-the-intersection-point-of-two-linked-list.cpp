// http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

#include <iostream>
#include "linkedList.h"

int getIntesectionNode(node *head1, node *head2) {
	int c = 0;
	node* ptr = head1;
	while(ptr){
		c++;
		ptr = ptr->next;
	}
	ptr = head2;
	while(ptr){
		c--;
		ptr = ptr->next;
	}
	if(c>0){
		ptr = head1;
		while(c>=0){
			ptr = ptr->next;
			c--;
		}
	}
	else {
		ptr = head2;
		while(c<=0){
			ptr = ptr->next;
			c++;
		}
	}
	return ptr->data;
}

int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newNode;
  struct node* head1 = new node;
  head1->data  = 10;
 
  struct node* head2 = new node;
  head2->data  = 3;
 
  newNode = new node;
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = new node;
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = new node;
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = new node;
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
  printList(head1);
  printList(head2);
 
  printf("\n The node of intersection is %d \n", getIntesectionNode(head2, head1));
}
  
