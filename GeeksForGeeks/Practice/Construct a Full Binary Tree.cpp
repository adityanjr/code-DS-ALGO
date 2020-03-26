/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/



/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
Node* make(int pre[], int left, int right){
    if(left <= right){
        int mid = left + (right-left)/2;
        
        Node* root = new Node();
        root->data = pre[left];
        root->left = make(pre, left+1, mid);
        root->right = make(pre, mid+1, right);
        
        return root;
    }
    
    return NULL;
}

// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    // Code here
    int left = 0, right = size-1;
    return make(pre, left, right);
}
