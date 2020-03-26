/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

int sum(Node* root, bool left){
    if(!root){
        return 0;
    }
    else if(!root->left && !root->right){
        if(left){
            return root->data;
        }
        return 0;
    }
    return sum(root->left, true) + sum(root->right, false);
}

// function should return the sum of all 
// left leaf nodes
int leftLeafSum(Node* root)
{
    // Code here
    return sum(root, false);
}
