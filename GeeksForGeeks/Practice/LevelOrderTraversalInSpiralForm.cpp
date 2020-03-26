/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void spiral(Node* root, vector<vector<int> >& sol, int level){
    if(!root){
        return;
    }
    if(sol.size() < level){
        vector<int> temp;
        sol.push_back(temp);
    }
    sol[level-1].push_back(root->data);
    
    spiral(root->left, sol, level+1);
    spiral(root->right, sol, level+1);
}


void printSpiral(Node *root)
{
    vector<vector<int> > sol;
    
    spiral(root, sol, 1);
    
    bool right = true;
    
    for(int i = 0; i < sol.size(); i++){
        int cols = sol[i].size();
        if(right){
            for(int j = cols-1; j >= 0; j--){
                cout << sol[i][j] << " ";
            }
        }
        else{
            for(int j = 0; j < cols; j++){
                cout << sol[i][j] << " ";
            }
        }
        right = !right;
    }
}
