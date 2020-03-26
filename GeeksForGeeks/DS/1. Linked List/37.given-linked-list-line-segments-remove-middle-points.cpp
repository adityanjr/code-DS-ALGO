// http://www.geeksforgeeks.org/given-linked-list-line-segments-remove-middle-points

#include <iostream>
using namespace std;

struct Node{
    int x, y;
    Node *next;
};

void push(struct Node ** head_ref, int x,int y)
{
    struct Node* new_node = new Node;
    new_node->x  = x;
    new_node->y  = y;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
 
/* Utility function to print a singly linked list */
void printList(Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("(%d,%d)-> ", temp->x,temp->y);
        temp = temp->next;
    }
    printf("\n");
 
}

void deleteMiddle(Node *head){
	if(head == NULL || head->next == NULL)
 	    return;
	Node *prev = head;
	Node *ptr = head->next;
	bool cond;
	while(prev && ptr && ptr->next){
		cond = ((prev->x == ptr->x) && (ptr->x == ptr->next->x) || ((prev->y == ptr->y) && (ptr->y == ptr->next->y)));
 	    if(cond){
 	    	prev->next = ptr->next;
 	    	delete(ptr);
 	    	ptr = prev->next;
 	    }
 	    else {
 	    	prev = ptr;
 	    	ptr = ptr->next;
 	    }
	}
}


int main(){
	Node *head = NULL;
 
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    printf("Given Linked List: \n");
    printList(head);
 	deleteMiddle(head);
        printf("Modified Linked List: \n");
        printList(head);
    return 0;
}
