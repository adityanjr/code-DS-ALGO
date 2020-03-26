// http://geeksquiz.com/linked-list-set-3-deleting-node/
#include "linkedList.h"

void delNode(node **head, int data){
	node *ptr = *head;
	if((*head)->data == data){
		*head = (*head)->next;
		delete(ptr);
		return;
	}
	node *prev = *head;
	while(ptr->data != data){
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = ptr->next;
	delete(ptr);
}

int main(){
	node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    delNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
