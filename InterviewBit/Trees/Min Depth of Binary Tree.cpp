/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    
    if(A==NULL)
        return 0;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    TreeNode* root = A;
    int depth = 0;
    
    while(!q.empty()) {
        A = q.front();
        q.pop();
        
        if(A==NULL) {
            depth++;
            if(!q.empty()) 
                q.push(NULL);
        }
        else if(A->left==NULL && A->right==NULL)
            return depth+1;
        else {
            if(A->left)
                q.push(A->left);
        
            if(A->right)
                q.push(A->right);
            
        }
    }
    return depth;
}
