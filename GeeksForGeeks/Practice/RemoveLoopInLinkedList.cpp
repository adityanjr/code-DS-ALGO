/*
The structure of linked list is the following
struct node
{
int data;
node* next;
};*/

/*The function removes the loop
from the linked list if present
You are required to complete this method*/
void removeTheLoop(node *list){
    node* slow = list;
    
    if(slow == NULL){
        return;
    }
    
    node* fast = list->next;
    
    while(slow != NULL && fast != NULL){
        if(slow == NULL){
            return;
        }
        if(fast->next == NULL){
            return;
        }
        if(slow == fast){
            break;
        }
        slow = slow->next;
        fast = (fast->next)->next;
    }
    
    slow = slow->next;
    slow->next = NULL;
    
    
}
