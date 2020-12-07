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
    int pathSumHelper(TreeNode* root, int currSum, int target, unordered_map<int, int>& preSum) {
        if(root == NULL) return 0;
        
        currSum += root->val;
        
        int res = preSum[currSum - target];
        
        preSum[currSum]++;
        
        res += pathSumHelper(root->left, currSum, target, preSum) + pathSumHelper(root->right, currSum, target, preSum);
        
        preSum[currSum]--;
        
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        return pathSumHelper(root, 0, sum, preSum);
    }
};