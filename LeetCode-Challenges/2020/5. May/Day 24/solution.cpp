/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Node
    {
        int value;
        struct Node *next;
        Node(int x) :value(x){}
    };
    private: TreeNode *root=new TreeNode();
    private: TreeNode *temp1=new TreeNode();
   // private: TreeNode *temp=new TreeNode();
    public:
    void Insert(TreeNode* temp,int value)
    {
        // cout<<temp->val<<" ";
        if(temp->val<value)
        {
            if(temp->right==NULL)
            {
                temp->right=new TreeNode();
                temp=temp->right;
                temp->val=value;
                cout<<temp->val<<" ";
            }
            else
            {
                temp=temp->right;
                Insert(temp,value);
            }
        }
        if(temp->val>value)
        {
            if(temp->left==NULL)
            {
                
                temp->left=new TreeNode();
                temp=temp->left;
                temp->val=value;
                cout<<temp->val<<" ";
            }
            else
            {
                temp=temp->left;
                Insert(temp,value);
            }
        }
    }

    
     TreeNode* bstFromPreorder(vector<int>& preorder) {
         root->val=preorder[0];
        temp1=root;
        //temp=root;
        for(int i=1;i<preorder.size();i++)
        {
            Insert(temp1,preorder[i]); 
            temp1=root;
        }
        return root;
    }
};