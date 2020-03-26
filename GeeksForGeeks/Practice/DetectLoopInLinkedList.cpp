/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/

int detectloop(Node *list)
{
   if(!list){
       return 0;
   }    
   
   Node* slow = list, *fast = list->next;
   
   while(fast != NULL){
       if(fast->next == NULL){
           break;
       }
       if(slow == fast){
            return 1;        
       }
       slow = slow->next;
       fast = (fast->next)->next;
   }
   
   return 0;
}
