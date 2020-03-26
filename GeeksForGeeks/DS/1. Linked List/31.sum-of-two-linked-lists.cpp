// http://www.geeksforgeeks.org/sum-of-two-linked-lists
// Head erpresent MSD

#include <iostream>
#include "linkedList.h"

int getSize(node *head){
	node *ptr = head;
	int count = 0;
	while(ptr){
		ptr = ptr->next;
		count++;
	}
	return count;
}

node* addCarryToList(node *head, int &carry){
	if(head == NULL)
	    return NULL;
	node *tmp = addCarryToList(head->next, carry);
	int data = head->data + carry;
	carry = data/10;
	node *p = new node;
	p->data = data%10;
	p->next = tmp;
	return p;
}

node *addEqualList(node *head1, node *head2, int &carry){
	if(head1 == NULL)
			 return NULL;
    node *tmp = addEqualList(head1->next, head2->next, carry);
    int data = head1->data + head2->data + carry;
	carry = data/10;
	node *p = new node;
	p->data = data%10;
	p->next = tmp;
	return p;
}

void addList(node *head1, node *head2, node **result){
	if(head1 == NULL){
		*result = head2;
		return;
	}
    else if(head2 == NULL){
    	 *result = head1;
		 return;
    }
  	 int n = getSize(head1);
  	 int m = getSize(head2);
  	 
  	 // head1 will always bigger than head2
  	 if(n < m){
  	 	node *tmp = head1;
  	 	head1 = head2;
  	 	head2 = tmp;
  	 	int t = n;
  	 	n = m;
  	 	m = t;
  	 }
	 int tmp = m;
  	 node *ptr = head1;
  	 node *prev = NULL;
  	 while(tmp < n){
	     prev = ptr;
	     ptr = ptr->next;
		 tmp++;
	}
	if(prev)
	    prev->next = NULL;
	int carry = 0;
	node *t = addEqualList(ptr, head2, carry);
	node *t1 = NULL;
	if(m != n){
		 t1 = addCarryToList(head1, carry);
		 node *ptr = t1;
		 while(ptr->next){
	  	     ptr = ptr->next;
		 }	
		 ptr->next = t;	 
	}
	else {
		t1 = t;
	}
	
	if(carry){
		node *t2 = new node;
		t2->data = 1;
		t2->next = t1;
		*result = t2;
	}
	else {
		*result = t1;
	}
}

int main(){
	
	node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = {9, 9, 9};
    int arr2[] = {1, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create first list as 9->9->9
    int i;
    for (i = size1-1; i >= 0; --i)
        push(&head1, arr1[i]);

    // Create second list as 1->8
    for (i = size2-1; i >= 0; --i)
        push(&head2, arr2[i]);

    addList(head1, head2, &result);
    printList(result);

    return 0;
}
