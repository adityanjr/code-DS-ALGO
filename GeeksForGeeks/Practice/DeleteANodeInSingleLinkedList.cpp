/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
    int count = 1;
    
    Node* newHead = NULL;
    Node* curr = head;
    Node* last = NULL;
    
    while(count < x){
        Node* temp = curr->next;
        last = curr;
        curr = temp;
        
        if(!newHead){
            newHead = last;
        }
           
        count++;
    }
    
    if(last){
        if(curr){
            last->next = curr->next;
        }
        else{
            last->next = NULL;
        }
    }
    else{
        newHead = curr->next;
    }
    
    return newHead;
}
