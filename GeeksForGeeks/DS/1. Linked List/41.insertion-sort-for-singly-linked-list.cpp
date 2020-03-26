// http://geeksquiz.com/insertion-sort-for-singly-linked-list/

#include <iostream>
#include "linkedList.h"

void insert(node **head, node *p){
	node *ptr = *head;
	if((*head)->data > p->data){
		p->next = *head;
		(*head) = p;
		return;
	}
	while(ptr->next && p->data > ptr->next->data){
		ptr = ptr->next;
	}
	p->next = ptr->next;
	ptr->next = p;
}

void insertionSort(node **head){
	if((*head) == NULL || (*head)->next==NULL)
		return;
	node *res = (*head);
	node *ptr = (*head)->next;
	res->next = NULL;
	while(ptr){
		node *next = ptr->next;
		ptr->next = NULL;
		insert(&res, ptr);
		ptr = next;
	}
	*head = res;
}

int main(){
	struct node *a = NULL;
    append(&a, 5);
    append(&a, 20);
    append(&a, 4);
    append(&a, 3);
    append(&a, 30);

    printf("Linked List before sorting \n");
    printList(a);

    insertionSort(&a);

    printf("\nLinked List after sorting \n");
    printList(a);
	return 0;
}
