// https://www.interviewbit.com/problems/invert-the-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A) {
        invertTree(A->left);
        invertTree(A->right);
        TreeNode* temp = A->left;
        A->left = A->right;
        A->right = temp;
    }
    return A;
}
