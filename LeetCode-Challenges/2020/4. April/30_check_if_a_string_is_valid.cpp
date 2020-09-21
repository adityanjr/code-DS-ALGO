class Solution
{
public:
    bool dfs(TreeNode *root, int i, vector<int> &arr)
    {
        if (root->val != arr[i])
        {
            return false;
        }

        int n = arr.size();

        if (i == n - 1)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return true;
            }
            return false;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (i == n - 1 && root->val == arr[i])
            {
                return true;
            }
            return false;
        }

        if (root->left != NULL && root->right == NULL)
        {
            return dfs(root->left, i + 1, arr);
        }
        else if (root->left == NULL && root->right != NULL)
        {
            return dfs(root->right, i + 1, arr);
        }

        bool left = dfs(root->left, i + 1, arr);
        bool right = dfs(root->right, i + 1, arr);

        return (left || right);
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return dfs(root, 0, arr);
    }
};