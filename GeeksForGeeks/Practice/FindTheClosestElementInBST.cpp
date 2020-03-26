/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void maxD(Node* root, int k, int& ans){
    if(!root){
        return;
    }
    else if(abs(root->data - k) < abs(ans - k)){
        ans = abs(root->data);
    }
    
    maxD(root->left, k, ans);
    maxD(root->right, k, ans);
}

int maxDiff(Node *root, int k)
{
    int ans = INT_MAX;
    
    maxD(root, k, ans);
    
    return ans;
}
