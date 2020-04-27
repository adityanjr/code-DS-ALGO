//  https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildBST(int l, int r, const vector<int> &A) {
    if(l==r)
        return NULL;
    int mid = (l+r)>>1;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = buildBST(l, mid, A);
    root->right = buildBST(mid+1, r, A);
    
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l = 0;
    int r = A.size();
    
    TreeNode* root = buildBST(l, r, A);
    return root;
}

