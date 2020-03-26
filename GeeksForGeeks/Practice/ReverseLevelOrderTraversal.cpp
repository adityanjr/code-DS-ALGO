/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void make(Node* root, int level, vector<vector<int> >& temp){
    if(!root){
        return;
    }
    if(level > temp.size()){
        vector<int> t;
        temp.push_back(t);
    }
    
    temp[level-1].push_back(root->data);
    
    make(root->left, level+1, temp);
    make(root->right, level+1, temp);
}

void reversePrint(Node *root)
{
    //Your code here
    vector<vector<int> > temp;
    
    make(root, 1, temp);
    
    int n = temp.size();
    
    while(n){
        for(int i = 0; i < temp[n-1].size(); i++){
            cout << temp[n-1][i] << " ";
        }
        n--;
    }
}
