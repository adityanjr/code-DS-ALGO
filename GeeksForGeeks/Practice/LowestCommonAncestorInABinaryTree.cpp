/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
bool exists(Node* root, int key){
    if(!root){
        return false;
    }
    else if(root->data == key){
        return true;
    }
    
    return exists(root->left, key) || exists(root->right, key);
}

Node * LCA(Node* root ,int n1 ,int n2)
{
   //Your code here 
   if(!root){
       return NULL;
   }
   else if(root->data == n1 || root->data == n2){
       return root;
   }
   else if(exists(root->left, n1) && exists(root->right, n2)){
       return root;
   }
   else if(exists(root->right, n1) && exists(root->left, n2)){
       return root;
   }
   else if(exists(root->left, n1) && exists(root->left, n2)){
       return LCA(root->left, n1, n2);
   }
   return LCA(root->right, n1, n2);
}
