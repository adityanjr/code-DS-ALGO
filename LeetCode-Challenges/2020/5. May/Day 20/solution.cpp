class Solution {

public:
    stack <int> s;
    void Fill (TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        Fill(root->right);
        s.push(root->val);
        Fill(root->left);
    }
    int kthSmallest(TreeNode* root, int k) {
        Fill(root);
        k=k-1;
        while(!s.empty() && k>0)
        {
            s.pop();
            k--;
        }
        return s.top();
    }
};
