/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    Node* curr = NULL, *curr1 = node1, *curr2 = node2;
    
    while(curr1 && curr2){
        Node* temp1 = curr1->next, *temp2 = curr2->next;
        if(curr1->data < curr2->data){
            curr1->next = curr;
            curr = curr1;
            curr1 = temp1;
        }
        else{
            curr2->next = curr;
            curr = curr2;
            curr2 = temp2;
        }
    }
    
    while(curr1){
        Node* temp1 = curr1->next;
        curr1->next = curr;
        curr = curr1;
        curr1 = temp1;
    }
    
    while(curr2){
        Node* temp2 = curr2->next;
        curr2->next = curr;
        curr = curr2;
        curr2 = temp2;
    }
    
    return curr;
}
