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
    int intAns;
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int intLeftSum = dfs(root -> left);
        int intRightSum = dfs(root -> right);
        //cout << intLeftSum << "  :  " << intRightSum << '\n'; 
        intAns = max(intAns , intRightSum + intLeftSum + root -> val);
        return max(0, root->val + max(intLeftSum , intRightSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        intAns = INT_MIN;
        dfs(root);
        return intAns;
    }
};
