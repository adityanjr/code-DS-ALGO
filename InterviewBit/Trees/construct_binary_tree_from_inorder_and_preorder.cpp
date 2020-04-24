//  https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findIndex(vector<int> &A, int l, int r, int num ) {
    int i = 0;
    for(i=l;i<r;i++)
        if(A[i]==num)
            break;
    return i;
}
TreeNode* buildBTree(vector<int> &A, vector<int> &B, int l, int r, int *PI) {
    if(l==r)
        return NULL;
    
    TreeNode* root = new TreeNode(A[*PI]);
    (*PI)++;
    
    int index = findIndex(B, l, r, root->val);
    
    root->left = buildBTree(A, B, l, index, PI);
    root->right = buildBTree(A, B, index+1, r, PI);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int l = 0;
    int r = A.size();
    int PI = 0;
    
    if(r==0)
        return NULL;
    TreeNode* root = buildBTree(A, B, l, r, &PI);
    return root;
}

