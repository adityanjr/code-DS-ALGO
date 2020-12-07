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
    void dfs(TreeNode* root, int x, int y, vector<pair<int, pair<int, int>>>& list) {
        if(root == NULL) return;
        
        list.push_back(make_pair(root->val, make_pair(x, y)));
        
        dfs(root->left, x - 1, y - 1, list);
        dfs(root->right, x + 1, y - 1, list);
    }
public:
    static bool compare(pair<int, pair<int, int>> L1, pair<int, pair<int, int>> L2) {
        // If x is same
        if(L1.second.first == L2.second.first) {
            // If y is same
            if(L1.second.second == L2.second.second) {
                return L1.first < L2.first;
            } else {
                return L1.second.second > L2.second.second;
            }
        } else {
            return L1.second.first < L2.second.first; 
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<pair<int, pair<int, int>>> list;
        map<int, vector<int>> m;
        
        dfs(root, 0, 0, list);
        
        sort(list.begin(), list.end(), compare);
        
        for(pair<int, pair<int, int>> l: list) {
            vector<int> line;
            
            if(m.find(l.second.first) != m.end()) {
                line = m[l.second.first];
            } else {
                line = {};
            }
            
            line.push_back(l.first);
            m[l.second.first] = line;
        }
        
        for(auto &x: m) {
            res.push_back(x.second);
        }
        
        return res;
    }
};