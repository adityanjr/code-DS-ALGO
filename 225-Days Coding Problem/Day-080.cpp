/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     char val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val('0'), left(nullptr), right(nullptr) {}
 *     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int deepest_height;
    char character;
    void getDeepestHeight(TreeNode* root, int current_height) {
        if (root == nullptr) {
            return ;
        }
        if (deepest_height < current_height) {
            deepest_height = current_height;
            character = root -> val;
        }
        getDeepestHeight(root -> right, current_height+1);
        getDeepestHeight(root -> left, current_height+1);
    }
public:
    char maxDepth(TreeNode* root) {
        deepest_height=0;
        getDeepestHeight(root, 1);
        return character;
    }
};

