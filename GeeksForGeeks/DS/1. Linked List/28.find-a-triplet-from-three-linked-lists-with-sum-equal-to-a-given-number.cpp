// http://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number

#include<iostream>
#include "linkedList.h"
#include <algorithm>

void isSumSorted(node *a, node *b, node *c, int num){
	while(a){
		int d = num - a->data;
		if(d <=0)
			continue;
		node *headB = b;
		node *headC = c;
		while(headB != NULL && headC != NULL){
			if(headB->data + headC->data == d){
				cout<<a->data<<" "<<headB->data<<" "<<headC->data;
				return;
			}
			else if(headB->data + headC->data < d)
				headB = headB->next;
			else
				headC = headC->next;
		}
		a = a->next;
	}
	cout<<"No such";
}

int main(){
	node* headA = NULL;
    struct node* headB = NULL;
    struct node* headC = NULL;
 
    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    /*create another sorted linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
 	
    int givenNumber = 26;
    isSumSorted (headA, headB, headC, givenNumber);
	return 0;
}

