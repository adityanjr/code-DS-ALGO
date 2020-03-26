/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/

/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root == NULL){
       return root;
   }
   
   int maxi = max(n1, n2), mini = min(n1, n2);
   
   if((root->data >= mini) && (root->data <= maxi)){
       return root;
   }
   else if(root->data < mini){
       return LCA(root->right, n1, n2);
   }     
   return LCA(root->left, n1, n2);
}
