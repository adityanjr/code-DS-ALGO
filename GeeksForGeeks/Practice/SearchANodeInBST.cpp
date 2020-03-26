/* Node structure 
struct node {
    int data;
   struct node * right, * left;
};*/


/*You are required to complete this method*/
bool search(node* root, int x)
{
    //Your code here
    if(!root){
        return false;
    }
    else if(root->data == x){
        return true;
    }
    else if(root->data > x){
        return search(root->left, x);
    }
    return search(root->right, x);
}

