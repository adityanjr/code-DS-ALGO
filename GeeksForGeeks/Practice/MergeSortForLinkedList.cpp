/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure of the linked list node is as
struct node
{
	int data;
	struct node* next;
};
*/
/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    // Code here
    if(!source){
        return;
    }
    
    node* slow = source, *fast = source->next;
    
    while(fast){
        if(fast->next == NULL){
            break;
        }
        slow = slow->next;
        fast = (fast->next)->next;
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
    
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
    // Code here
    if(!a){
        return b;
    }
    else if(!b){
        return a;
    }
    
    node* head = NULL;
    
    if(a->data < b->data){
        head = a;
        head->next = mergeList(a->next, b);
    }
    else{
        head = b;
        head->next = mergeList(a, b->next);
    }
    
    return head;
    
    // node* head = NULL, *curr = NULL;
    
    // while(a && b){
    //     if(a->data > b->data){
    //         if(head){
    //             curr->next = b;
    //             curr = curr->next;
    //         }    
    //         else{
    //             curr = b;
    //             head = b;
    //         }
    //         b = b->next;
    //     }
    //     else{
    //         if(head){
    //             curr->next = a;
    //             curr = curr->next;
    //         }    
    //         else{
    //             curr = a;
    //             head = a;
    //         }
    //         a = a->next;
    //     }
    // }
    
    // while(a){
    //     if(head){
    //         curr->next = a;
    //         curr = curr->next;
    //     }    
    //     else{
    //         curr = a;
    //         head = a;
    //     }
    //     a = a->next;
    // }
    
    // while(b){
    //     if(head){
    //         curr->next = b;
    //         curr = curr->next;
    //     }    
    //     else{
    //         curr = b;
    //         head = b;
    //     }
    //     b = b->next;
    // }
    
    return head;
}
