//  https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A, vector<int> &data) {
    if(!A)
        return;
    inorder(A->left, data);
    data.push_back(A->val);
    inorder(A->right, data);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> data;
    inorder(A, data);
    return data[B-1];
}
