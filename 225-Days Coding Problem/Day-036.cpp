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
    int ans;
    bool isAnsFound;
    int tempCounter;
    void getans(TreeNode* root , int k){
        if(isAnsFound){
            return;
        }
        if(root->right!=nullptr){
            getans(root->right , k);
        }
        tempCounter++;
        if(k==tempCounter){
            isAnsFound = true;
            ans = root -> val;
            tempCounter++;
            return;
        }
        if(!isAnsFound && root->left != nullptr){
            getans(root->left , k);
        }
        if(k==tempCounter){
            isAnsFound = true;
            ans = root -> val;
            return;
        }
    }
public:
    int kthSmallest(TreeNode* root) {
        tempCounter =0;
        ans = -1;
        isAnsFound = false;
        getans(root , 2);
        return ans;
    }
};
