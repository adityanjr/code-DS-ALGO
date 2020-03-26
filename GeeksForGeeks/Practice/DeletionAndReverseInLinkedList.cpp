/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/
/* Function to delete a given node from the list */
void deleteNode(struct Node *head, int key)
{
// Your code goes here
    Node *prev = head;
    
    while(prev->next != head){
        prev = prev->next;
    }
    
    Node* curr = head;
    
    while(curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
}
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
// Your code goes here
    Node* prev = *head_ref;
    
    while(prev->next != *head_ref){
        prev = prev->next;
    }
    
    Node* curr = *head_ref, *mark = *head_ref;
    
    do{
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }while(curr != mark);
    
    *head_ref = prev;
    
}
