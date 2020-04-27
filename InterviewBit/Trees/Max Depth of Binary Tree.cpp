/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    int l_depth = maxDepth(A->left);
    int r_depth = maxDepth(A->right);
    if(l_depth > r_depth)
        return l_depth+1;
    return r_depth+1;
}
