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

/*
    Complexity Analysis: DFS Solution

    Time - O(N)
    Space - O(N)
*/

class Solution {
    void dfs(TreeNode* root, int level, vector<vector<int>>& values) {
        if(root == NULL) return;
        if(level == (int)values.size()) values.push_back({});
        
        values[level].push_back(root->val);
        
        dfs(root->left, level + 1, values);
        dfs(root->right, level + 1, values);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> values;
        dfs(root, 0, values);
        reverse(values.begin(), values.end());
        return values;
    }
};

/*
    Complexity Analysis: BFS Solution

    Time - O(N)
    Space - O(N)
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> values;
        vector<int> level;
        queue<TreeNode*> q;
        
        q.emplace(root);
        int n = q.size();
        
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            level.push_back(current->val);
            --n;
            
            if(current->left) {
                q.emplace(current->left);
            }
            
            if(current->right) {
                q.emplace(current->right);
            }
            
            
            if(n == 0) {
                n = q.size();
                values.push_back(level);
                level = {};
            }
        }
        
        reverse(values.begin(), values.end());
        return values;
    }
};