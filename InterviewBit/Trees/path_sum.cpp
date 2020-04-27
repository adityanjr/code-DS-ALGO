//  https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    
    if(A==NULL)
        return (B==0)?1:0;
    else {
        int sum = B-(A->val);
        if((A->left && A->right) || (!A->left && !A->right))
            return (hasPathSum(A->left, sum) || hasPathSum(A->right, sum));
        else if(A->left)
            return hasPathSum(A->left, sum);
        else
            return hasPathSum(A->right, sum);
    }
}

