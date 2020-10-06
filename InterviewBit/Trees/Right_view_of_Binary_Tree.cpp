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
    {
        return res;
    }
    
    q.push(A);
    while(!q.empty())
    {
        int n = q.size();
        TreeNode* last = NULL;
        
        for(int i=0;i<n;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
            
            last = node;
        }
        res.push_back(last->val);
    }
    
    return res;
}