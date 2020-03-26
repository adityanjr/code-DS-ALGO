/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   Node* slow = head, *fast = head;
   
   while(fast){
       if(!fast->next){
           break;
       }
       fast = (fast->next)->next;
       slow = slow->next;
   }
   
   return slow->data;
}
