//  https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildBTree(vector<int> &A, int l, int r) {
    if(l==r)
        return NULL;
    
    int maxm = *max_element(A.begin()+l, A.begin()+r);

    int dist;
    for(int i=l;i<r;i++)
        if(maxm == A[i]) {
            dist = i;
            break;
        }
    
    TreeNode* root = new TreeNode(A[dist]);
    root->left = buildBTree(A, l, dist);
    root->right = buildBTree(A, dist+1, r);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    int n = A.size();
    if(n==0)
        return NULL;
    
    TreeNode* root = buildBTree(A, 0, n);
    
    return root;
}

