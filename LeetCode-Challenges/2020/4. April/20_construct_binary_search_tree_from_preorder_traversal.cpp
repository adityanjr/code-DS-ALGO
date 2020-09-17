class Solution
{
    TreeNode *createTree(vector<int> &pre, int i, int limit)
    {

        TreeNode *root = new TreeNode(pre[i]);

        //Leaf node
        if (i == limit - 1)
        {
            return root;
        }

        //Only right child
        if (pre[i + 1] > pre[i])
        {
            TreeNode *right = createTree(pre, i + 1, limit);
            root->right = right;
            return root;
        }

        int j;

        for (j = i + 1; j < limit; j++)
        {
            if (pre[j] > pre[i])
            {
                break;
            }
        }

        //only left child
        if (j == limit)
        {
            TreeNode *left = createTree(pre, i + 1, limit);
            root->left = left;
            return root;
        }

        //both children
        TreeNode *left = createTree(pre, i + 1, j);
        TreeNode *right = createTree(pre, j, limit);
        root->left = left;
        root->right = right;
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        return createTree(preorder, 0, n);
    }
};