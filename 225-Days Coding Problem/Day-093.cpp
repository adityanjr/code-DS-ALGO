/**
 * Definition for binary tree
 *
 *      struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *      };
 */
class Solution {
    private:
        struct Node{
            bool isBST;
            int ans;
            int min_value;
            int max_value;
        };
        Node getBST(TreeNode * root){
            if(root == nullptr){
                return {1,0,INT_MAX,INT_MIN};
            }
            Node left = getBST(root->left);
            Node right = getBST(root->right);
            Node currentNode;
            if(left.isBST==false || right.isBST==false || left.max_value>root->val || right.min_value <= root->val) {
                currentNode.isBST = false;
                currentNode.ans = max(left.ans , right.ans);
                return currentNode;
            }
            currentNode.isBST = true;
            currentNode.ans = left.ans + right.ans + 1;
            currentNode.min_value = root->left != nullptr ? left.min_value : root->val;
            currentNode.max_value = root->right != nullptr ? right.max_value : root -> val;
            return currentNode;
        }
    public:
        int maxSizeBST(TreeNode *root) {
            Node Ans = getBST(root);
            return Ans.ans;
        }
};

