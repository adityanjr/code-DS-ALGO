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

    bool isCousins(TreeNode* root, int x, int y) {
        queue <pair<TreeNode *,int>> q;
        TreeNode * temp=new TreeNode();
        TreeNode *temp1=new TreeNode();
        TreeNode *temp2=new TreeNode();
        temp=root;
        q.push(make_pair(temp,0));
        int x1,y1;
        while(!q.empty())
        {
            pair<TreeNode *,int> top=q.front();
            q.pop();
            if( (top.first->right!=NULL && (top.first)->right->val==x) ||
               ( top.first->left!=NULL && (top.first)->left->val==x))
            {
                temp1=top.first;
                x1=top.second+1;
            }
            if( (top.first->right!= NULL && (top.first)->right->val==y) ||
               ( top.first->left!= NULL && (top.first)->left->val==y))
            {
                temp2=top.first;
                y1=top.second+1;
            }
            if(top.first->right!=NULL)
            {
                q.push(make_pair(top.first->right,top.second+1));
            }
            if(top.first->left!=NULL)
            {
                q.push(make_pair(top.first->left,top.second+1));
            }
        }
        if(x1==y1 && temp1!=temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
