/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
void make(Node* root, int width, map<int, int>& m){
    if(!root){
        return;
    }
    
    if(m.find(width) == m.end()){
        m[width] = root->data;
    }
    else{
        m[width] += root->data;
    }
    
    make(root->left, width-1, m);
    make(root->right, width+1, m);
}

void printVertical(Node *root)
{
//add code here.
    map<int, int> m;
    make(root, 0, m);
    
    map<int, int> :: iterator it = m.begin();
    
    while(it != m.end()){
        cout << it->second << " ";
        it++;
    }
}
