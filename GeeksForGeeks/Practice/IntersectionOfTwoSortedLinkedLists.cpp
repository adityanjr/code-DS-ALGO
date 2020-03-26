/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of the Linked list Node is as follows:
struct Node {
    int val;
    struct Node* next;
}; */
void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    Node* temp = NULL;
    Node** temp1 = head1;
    Node** temp2 = head2;
    
    while(*temp1 != NULL && *temp2 != NULL){
        if((*temp1)->val == (*temp2)->val){
            if(*head3){
                temp->next = *temp1;
                temp = *temp1;
            }
            else{
                *head3 = *temp1;
                temp = *head3;
            }
            *temp1 = (*temp1)->next;
            *temp2 = (*temp2)->next;
        }
        else if((*temp1)->val > (*temp2)->val){
            *temp2 = (*temp2)->next;
        }
        else{
            *temp1 = (*temp1)->next;
        }
    }
    
    if(temp){
        temp->next = NULL;
    }
}
