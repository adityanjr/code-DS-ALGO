/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) 
{
    queue<TreeNode*> q;
    q.push(A);
    
    bool left = false,right = false,flag = false;
    vector<int> arr;
    
    while(!q.empty())
    {
        int size = q.size();
        if(flag && left)
        {
            while(size--)
            {
                if(q.front()->val!=B && q.front()->val!=INT_MIN)
                    arr.push_back(q.front()->val);
                q.pop();
            }
            return arr;
        }
        else if(flag && right)
        {
            
            while(size--)
            {
                if(q.front()->val!=B && q.front()->val!=INT_MIN)
                    arr.push_back(q.front()->val);
                q.pop();
            }
            return arr;
        }
        else if(flag)
        {
            while(size--)
            {
                if(q.front()->val!=B && q.front()->val!=INT_MIN)
                    arr.push_back(q.front()->val);
                q.pop();
            }
            return arr;
        }
        
        while(size--)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->right)
            {
                if(curr->right->val == B)
                {
                    flag = true;
                    if(curr->left)
                    {
                        left = true;
                        curr->left->val = INT_MIN;
                    }
                }
                q.push(curr->right);
            }
            if(curr->left)
            {
                if(curr->left->val == B)
                {
                    flag = true;
                    if(curr->right)
                    {
                        right = true;
                        curr->right->val = INT_MIN;
                    }
                }
                q.push(curr->left);
            }
        }
    }
}