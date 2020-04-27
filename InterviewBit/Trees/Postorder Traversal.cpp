/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> data;
    if(!A)
        return data;
    st.push(A);
    
    TreeNode* prev = NULL;
    while(!st.empty()) {
        TreeNode* curr = st.top();
        
        if(!prev || prev->left==curr || prev->right==curr) {
            if(curr->left)
                st.push(curr->left);
            else if(curr->right)
                st.push(curr->right);
        }
        else if(curr->left==prev) {
            if(curr->right)
                st.push(curr->right);
        }
        else {
            data.push_back(curr->val);
            st.pop();
        }
        prev = curr;
    }
    return data;
}
`