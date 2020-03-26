/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */

void sum(Node* root, vector<int>& sol, int level){
    if(!root){
        return;
    }
    if(sol.size() < level){
        sol.push_back(root->data);
    }
    else{
        sol[level-1] = sol[level-1] + root->data;
    }
    sum(root->left, sol, level+1);
    sum(root->right, sol, level+1);
}

int maxLevelSum(Node * root)
{
    vector<int> sol;
    sum(root, sol, 1);
    
    int ans = INT_MIN;
    
    for(int i = 0; i < sol.size(); i++){
        ans = max(ans, sol[i]);
    }
    
    if(ans == INT_MIN){
        return 0;
    }
    
    return ans;
}

