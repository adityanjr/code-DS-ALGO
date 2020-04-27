/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<struct TreeNode*> st;
    vector<int> values;
    while(1) {
        while(A) {
            st.push(A);
            A = A->left;
        }
        if(st.empty())
            break;
        A = st.top();
        st.pop();
        values.push_back(A->val);
        A = A->right;
    }
    return values;
}
