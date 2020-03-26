/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head,int x)
{
    Node* newHead = NULL;
    Node* curr = head;
    Node* last = NULL;
    
    while(curr){
        if(curr->data != x){
            if(!newHead){
                newHead = curr;
                last = newHead;
            }
            else{
                last->next = curr;
                last = curr;
            }
        }
        curr = curr->next;
    }
    
    if(last){
        last->next = NULL;
    }
    
    return newHead;
}
