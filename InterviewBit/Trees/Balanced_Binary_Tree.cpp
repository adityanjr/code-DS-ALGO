/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;

int depth(TreeNode* root, int d){
    if (root==NULL){
        return d-1;
    }
    
    int left = depth(root->left, d+1);
    int right = depth(root->right, d+1);
    
    if(abs(left-right)>1){
        ans = 0;
        return 0;
    }
    
    return max(left,right);
} 

int Solution::isBalanced(TreeNode* A) {
    ans = 1;
    int k = depth(A, 0);
    
    return ans;
}