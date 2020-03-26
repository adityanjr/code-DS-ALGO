/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node* head = NULL, *curr = NULL, *curr1 = head1, *curr2 = head2;
    
    while(curr1 && curr2){
        Node* temp1 = curr1->next, *temp2 = curr2->next;
        if(curr1->data < curr2->data){
            if(curr){
                curr->next = curr1;
                curr = curr1;
            }
            else{
                curr = curr1;
                head = curr;
            }
            curr1 = temp1;
        }
        else{
            if(curr){
                curr->next = curr2;
                curr = curr2;
            }
            else{
                curr = curr2;
                head = curr;
            }
            curr2 = temp2;
        }
    }
    
    while(curr1){
        Node* temp1 = curr1->next;
        if(curr){
            curr->next = curr1;
            curr = curr1;
        }
        else{
            curr = curr1;
            head = curr;
        }
        curr1 = temp1;
    }
    
    while(curr2){
        Node* temp2 = curr2->next;
        if(curr){
            curr->next = curr2;
            curr = curr2;
        }
        else{
            curr = curr2;
            head = curr;
        }
        curr2 = temp2;
    }
    
    return head;
}
