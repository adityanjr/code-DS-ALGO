void make(Node* root, vector<vector<int> >& temp, int curr){
    if(!root){
        return;
    }
    
    if(curr > temp.size()){
        vector<int> t;
        temp.push_back(t);
    }
    
    temp[curr-1].push_back(root->key);
    
    make(root->left, temp, curr+1);
    make(root->right, temp, curr+1);
}

/* Function to print corner node at each level */
void printCorner(Node *root)
{
    vector<vector<int> > temp;
    
    make(root, temp, 1);
    
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i][0] << " ";
        if(temp[i].size() != 1){
            cout << temp[i][temp[i].size()-1] << " ";
        }
    }
    
// Your code goes here

}
