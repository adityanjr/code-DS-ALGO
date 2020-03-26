// http://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it

#include "linkedList.h"

void delNode(node *ptr){
	node *tmp = ptr->next;
	ptr->data = tmp->data;
	ptr->next = tmp->next;
	delete(tmp);
}

int main(){
	node* head = NULL;
 
    /* Use push() to construct below list
    1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    printf("\n Before deleting \n");
    printList(head);
 
    /* I m deleting the head itself.
        You can check for more cases */
    delNode(head->next);
    printf("\n After deleting \n");
    printList(head);
    return 0;
}
