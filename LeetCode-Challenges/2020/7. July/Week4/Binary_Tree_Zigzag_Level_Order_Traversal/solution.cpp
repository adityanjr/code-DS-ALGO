/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        int level = 0;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            bool fromLeft = level % 2 == 0;
            int n = q.size();
            vector<int> levelNodes;
            
            while(n--) {
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left) {
                    q.push(current->left);
                }
                
                if(current->right) {
                    q.push(current->right);
                }
                
                levelNodes.push_back(current->val);
            }
            
            if(fromLeft) result.push_back(levelNodes);
            else {
                reverse(levelNodes.begin(), levelNodes.end());
                result.push_back(levelNodes);
            }
            
            level++;
        }
        
        return result;
    }
};