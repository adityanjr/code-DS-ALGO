/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int countNode(TreeNode* A) {
    if(!A)
        return 0;
    return 1+countNode(A->left)+countNode(A->right);
}
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    int diff = (countNode(B)-countNode(A));
    return (diff<0)?-1:diff;
}
