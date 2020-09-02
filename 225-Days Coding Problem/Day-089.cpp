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
    bool isValidBST(TreeNode* root, const std::optional<int64_t> &min_value=LLONG_MIN , const std::optional<int64_t>&max_value=LLONG_MAX) {
        if(root == nullptr){
            return true;
        }
        // according to DCP question binary search tree node can have equal value
        if(root -> val > max_value.value() || root->val < min_value.value()){
            return false;
        }
        return isValidBST(root->right,root->val,max_value) && isValidBST(root->left,min_value,root->val);
    }
};

