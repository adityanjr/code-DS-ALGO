//  https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int> > levels;
    if(!A)
        return levels;
    vector<int> level;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    
    while(!q.empty()) {
        A = q.front();
        q.pop();
        
        if(A==NULL) {
            if(!q.empty()) 
                q.push(NULL);
            levels.push_back(level);
            level.clear();
        }
        else {
            level.push_back(A->val);
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
    }
    return levels;
}

