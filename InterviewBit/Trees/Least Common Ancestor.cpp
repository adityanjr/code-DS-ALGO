//  https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

bool find(TreeNode* A, int B) {
    if(!A)
        return false;
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()) {
        A = q.front();
        q.pop();
        if(A->val == B)
            return true;
        if(A->left)
            q.push(A->left);
        if(A->right)
            q.push(A->right);
    }
    return false;
}
TreeNode* LCA(TreeNode* A, int B, int C) {
    if(!A || A->val==B || A->val==C)
        return A;
    TreeNode* left = LCA(A->left, B, C);
    TreeNode* right = LCA(A->right, B, C);
    
    if(left && right)
        return A;
    return (left?left:right);
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!find(A, B) || !find(A, C))
        return -1;
        
    TreeNode* ancestor = LCA(A, B, C);
    if(ancestor)
        return ancestor->val;
    return -1;
}
