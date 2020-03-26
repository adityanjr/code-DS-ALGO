// http://www.geeksforgeeks.org/maximum-sum-linked-list-two-sorted-linked-lists-common-nodes

#include <iostream>
#include "linkedList.h"

void finalMaxSumList(node *head1, node *head2){
	node *ptr1 = head1;
	node *prev1 = head1;
	node *ptr2 = head2;
	node *prev2 = head2;
	int sum1 = 0, sum2 = 0;
	while(ptr1 && ptr2){
		if(ptr1->data == ptr2->data){
			if(sum1 > sum2){
				while(prev1 != ptr1){
					cout<<prev1->data<<" ";
					prev1 = prev1->next;
				}
			}
			else {
				while(prev2 != ptr2){
					cout<<prev2->data<<" ";
					prev2 = prev2->next;
				}
			}
			cout<<ptr1->data<<" ";
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
			prev1 = ptr1;
			prev2 = ptr2;
			sum1 = sum2 = 0;
		}
		else if(ptr1->data < ptr2->data){
			sum1 += ptr1->data;
			ptr1= ptr1->next;
		}
		else {
			 sum2 += ptr2->data;
			 ptr2 = ptr2->next;
		}
	}
	if(ptr1 == NULL)
	    ptr1 = ptr2;
	while(ptr1){
		cout<<ptr1->data<<" ";
		ptr1= ptr1->next;
	}
}

int main(){

    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);
 
    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);

    finalMaxSumList(head1, head2);
    return 0;
}
