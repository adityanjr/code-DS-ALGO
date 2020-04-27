//  https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> inOrder(TreeNode* A) {
    vector<int> data;
    if(!A)
        return data;
    stack<TreeNode*> st;
    while(1) {
        while(A) {
            st.push(A);
            A = A->left;
        }
        if(st.empty())
            break;
        A = st.top();
        st.pop();
        data.push_back(A->val);
        A = A->right;
    }
    return data;
}
int isPalin(vector<int> data) {
    int n = data.size();
    for(int i=0;i<n/2;i++) {
        if(data[i]!=data[n-1-i])
            return 0;
    }
    return 1;
}
int Solution::isSymmetric(TreeNode* A) {
    vector<int> data = inOrder(A);
    //cout << data.size();
    if(isPalin(data))
        return 1;
    return 0;
}



########## OR ###########


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int util(TreeNode* A, TreeNode* B) {
    if(!A && !B)
        return 1;
    if(!A || !B)
        return 0;
    if(A->val!=B->val)
        return 0;
    return util(A->left, B->right) && util(A->right, B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(!A)
        return 1;
    if(!A->left && !A->right)
        return 1;
    return util(A->left, A->right);
}

