/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method*/
Node * deleteK(Node *head,int K)
{
  //Your code here
  if(K == 0){
      return head;
  }
  else if(K == 1){
      return NULL;
  }
  
  Node* curr = head;
  Node* prev = NULL;
  
  int count = 1;
  
  while(curr){
      Node* temp = curr->next;
      
      if(count == K){
          count = 0;
          prev->next = temp;
      }
      else{
          prev = curr;
      }
      
      count++;
      curr = temp;
  }
  
  return head;
}
