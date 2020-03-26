/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
Node* reverse(Node *head)
{
    Node* last = NULL;
    Node* curr = head;
    
    while(curr){
        Node* temp = curr->next;
        curr->next = last;
        last = curr;
        curr = temp;
    }
    
    return last;
}
