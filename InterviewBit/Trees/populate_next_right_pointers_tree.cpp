//  https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    
    if(!A)
        return;
    
    q.push(A);
    q.push(NULL);
    
    TreeLinkNode *prev = NULL;
    
    while(!q.empty()) {
        A = q.front();
        q.pop();
        
        if(A==NULL) {
            if(!q.empty())
                q.push(NULL);
        }
        else {
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        if(prev)
            prev->next = A;
        prev = A;
    }
}
