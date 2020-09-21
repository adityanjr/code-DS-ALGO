class Solution
{
public:
    int ans = -1000000;

    int countMax(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans = max(ans, root->val);
            return root->val;
        }
        if (root->left != NULL && root->right == NULL)
        {
            int x = root->val;
            int l = countMax(root->left);
            ans = max({ans, x, x + l});
            return max(x, x + l);
        }
        if (root->left == NULL && root->right != NULL)
        {
            int x = root->val;
            int r = countMax(root->right);
            ans = max({ans, x, x + r});
            return max(x, x + r);
        }

        int r = countMax(root->right);
        int l = countMax(root->left);
        int x = root->val;
        ans = max({ans, x, x + l, x + r, x + l + r});
        return max({x, x + l, x + r});
    }

    int maxPathSum(TreeNode *root)
    {
        int x = countMax(root);
        ans = max(x, ans);
        return ans;
    }
};