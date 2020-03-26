/*Complete the function below
Node is as follows:
struct node_t
{
    int data;
    int lCount;
 
    node_t* left;
    node_t* right;
};*/
void check(node_t* root, int& curr, int& ans, int k){
    if(!root){
        return;
    }
    
    check(root->left, curr, ans, k);
    
    curr++;
    
    if(curr == k){
        ans = root->data;
        return;
    }
    
    check(root->right, curr, ans, k);
}

int k_smallest_element(node_t *root, int k)
{
//add code here.
    int temp = 0, ans = 0;
    
    check(root, temp, ans, k);
    
    return ans;
}
