// http://geeksquiz.com/search-an-element-in-a-linked-list-iterative-and-recursive

#include "linkedList.h"

bool search(node *head, int x){
	if(head == NULL)
		return 0;
    if(head->data == x)
        return true;
	return search(head->next, x);
}

int main(){
	node* head = NULL;
    int x = 21;
 
    /* Use push() to construct below list
     14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
 
    search(head, 21)? printf("Yes") : printf("No");
    return 0;
}
