/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

bool heap(Node* root, int val){
    if(!root){
        return true;
    }
    else if(root->data >= val){
        return false;
    }
    return heap(root->left, root->data) && heap(root->right, root->data);
}

/*You are required to complete this method */
bool isHeap(Node * tree)
{
 // Your code here
    return heap(tree->left, tree->data) && heap(tree->right, tree->data);
}
