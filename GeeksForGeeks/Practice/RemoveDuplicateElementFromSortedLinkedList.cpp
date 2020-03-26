/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/
Node *removeDuplicates(Node *root)
{
 // your code goes here
    Node* head = root;
    Node* temp = root;
    
    while(temp != NULL){
        Node* curr = temp->next;
        while((curr != NULL) && (curr->data == temp->data)){
            curr = curr->next;
        }
        temp->next = curr;
        temp = temp->next;
    }
    
    return head;
}
