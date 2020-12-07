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
    TreeNode* findMin(TreeNode* root) {
        TreeNode* current = root;
        
        while(current && current->left != NULL)
            current = current->left;
        
        return current;
        
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else {
            // Case 1: No Children
            if(root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            
            // Case 2: One Children
            else if(root->left == NULL) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if(root->right == NULL) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            
            // Case 3: Two Children
            else {
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};