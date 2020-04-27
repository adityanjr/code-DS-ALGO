/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPaths(TreeNode* A, int B, vector<vector<int> > &paths, vector<int> &path) {
    if(!B && !A->left && !A->right) {
        paths.emplace_back(path);
    }
    
    if(A->left) {
        path.emplace_back(A->left->val);
        findPaths(A->left, B-A->left->val, paths, path);
        path.pop_back();
    }
    
    if(A->right) {
        path.emplace_back(A->right->val);
        findPaths(A->right, B-A->right->val, paths, path);
        path.pop_back();
    }
    
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > paths;
    vector<int> path;
    
    if(!A)
        return paths;
    path.emplace_back(A->val);
    
    findPaths(A, B-A->val, paths, path);
    
    return paths;
}

