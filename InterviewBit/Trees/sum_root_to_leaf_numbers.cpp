/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPaths(TreeNode* A, vector<vector<int> > &paths, vector<int> &path) {
    if(!A->left && !A->right)
        paths.push_back(path);
    
    if(A->left) {
        path.push_back(A->left->val);
        findPaths(A->left, paths, path);
        path.pop_back();
    }
    
    if(A->right) {
        path.push_back(A->right->val);
        findPaths(A->right, paths, path);
        path.pop_back();
    }
} 

int Solution::sumNumbers(TreeNode* A) {
    vector<vector<int> > paths;
    vector<int> path;
    
    if(!A)
        return 0;
    
    path.push_back(A->val);
    findPaths(A, paths, path);
    
    int result = 0;
    for(auto p:paths) {
        int sum = 0;
        for(auto i: p)
            sum = (sum*10 + i)%1003;
        result = (result + sum)%1003;
    }
    return result;
}

