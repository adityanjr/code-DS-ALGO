/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    if(!head || !(head->next)){
        return true;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL){
        slow = slow->next;
        if(fast->next == NULL){
            break;
        }
        fast = (fast->next)->next;
    }
    
    Node* prev = NULL;
    
    while(slow){
        Node* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    Node* curr = head;
    
    while(curr && prev){
        if(curr->data != prev->data){
            return false;
        }
        curr = curr->next;
        prev = prev->next;
    }
    
    return true;
}
