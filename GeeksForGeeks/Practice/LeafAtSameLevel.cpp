/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

bool leaf(Node* root, int curr, int& level){
    if(!root){
        return true;
    }
    
    curr++;
    
    if(root->left == NULL && root->right == NULL){
        if(level == INT_MIN){
            level = curr;
        }
        else if(level != curr){
            return false;
        }
        return true;
    }
    
    return leaf(root->left, curr, level) && leaf(root->right, curr, level);
}

/*You are required to complete this method*/
bool check(Node *root)
{
    //Your code here
    int level = INT_MIN;
    
    return leaf(root, 0, level);
}
