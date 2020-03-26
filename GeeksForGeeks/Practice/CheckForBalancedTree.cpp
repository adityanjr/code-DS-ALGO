/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */

// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{   
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left) && isBalanced(root->right) && 
    abs(height(root->left) - height(root->right)) <= 1){
        return true;
    }
    
    return false;
}
