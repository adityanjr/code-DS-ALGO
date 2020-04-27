/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> result;
    stack<TreeNode*> st;
    
    while(1) {
        while(A) {
            result.push_back(A->val);
            st.push(A);
            A = A->left;
        }
        if(st.empty())
            break;
        A = st.top();
        st.pop();
        A = A->right;
    }
    return result;
}
