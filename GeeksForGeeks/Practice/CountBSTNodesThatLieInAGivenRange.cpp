/*

The structure of a BST node is as follows:

struct Node {
int data;
Node * right, * left;
};


*/

int getCountOfNode(Node *root, int l, int h)
{
    if(!root){
        return 0;
    }
    int ans = 0;
    
    if(root->data >= l && root->data <= h){
        ans = 1;
    }
    
    return ans + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
}
