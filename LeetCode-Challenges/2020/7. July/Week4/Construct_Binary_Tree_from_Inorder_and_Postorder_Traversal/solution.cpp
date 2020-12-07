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
    TreeNode* buildTreeHelper(vector<int>& inorder, int i, int j, vector<int>& postorder, int ii, int jj) {
        if(i >= j || ii >= jj) return NULL;
        
        int mid = postorder[jj - 1];
        
        auto f = find(inorder.begin() + i, inorder.begin() + j, mid);
        
        int dis = f - inorder.begin() - i;
        
        TreeNode* root = new TreeNode(mid);
        
        root->left = buildTreeHelper(inorder, i, i + dis, postorder, ii, ii + dis);
        root->right = buildTreeHelper(inorder, i + dis + 1, j, postorder, ii + dis, jj - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};