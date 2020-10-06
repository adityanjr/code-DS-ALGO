/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    vector<int> res;
    
    if(!A)
        return res;
        
    q.push(A);
    
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        
        while(node){
            res.push_back(node->val);
            
            if(node->left){
                q.push(node->left);
            }
            
            node=node->right;
        }
    }
    return res;
}