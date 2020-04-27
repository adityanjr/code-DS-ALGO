/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    //int level = 1;
    vector< vector<int> > nodes;
    vector<int> temp;
    while(!q.empty()) {
        A = q.front();
        q.pop();
        
        if(A)
            temp.push_back(A->val);
        
        if(A==NULL) {
            //level *= -1;
            nodes.push_back(temp);
            temp.clear();
            if(!q.empty())
                q.push(NULL);
        }
        else {
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
    }
    for(int i=1;i<nodes.size();i+=2)
        reverse(nodes[i].begin(), nodes[i].end());
    
    return nodes;
}
