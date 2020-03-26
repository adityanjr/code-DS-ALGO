/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     // Code here
     if(!head){
         return 0;
     }
     
     Node* slow = head, *fast = head->next;
     
     while(fast != slow){
         if(!fast || !fast->next){
             return 0;
         }
         slow = slow->next;
         fast = (fast->next)->next;
     }
     
     Node* temp = slow;
     
     int len = 0;
     
     do{
         len++;
         temp = temp->next;
     }while(slow != temp);
     
     return len;
}
