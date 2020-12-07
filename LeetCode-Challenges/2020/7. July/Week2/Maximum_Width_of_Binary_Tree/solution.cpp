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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, unsigned>> q;
        q.push({ root, 1 });
        unsigned answer = 1;
        
        
        while(!q.empty()) {
            answer = max(answer, q.back().second - q.front().second + 1);
            int size = q.size();
            
            while(size-- > 0) {
                TreeNode* temp = q.front().first;
                unsigned id = q.front().second;
                q.pop();
                
                if(temp->left) q.push({ temp->left, 2 * id });
                if(temp->right) q.push({ temp->right, 2 * id + 1 });
            }
        }
        
        return answer;
    }
};