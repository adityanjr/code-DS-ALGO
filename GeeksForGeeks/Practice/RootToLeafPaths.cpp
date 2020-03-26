/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

void print(Node* root, string s){
    if(!root){
        cout << s << "#";
        return;
    }
    s = s + to_string(root->data) + " ";
    
    if(root->left){
        print(root->left, s);    
    }
    if(root->right){
        print(root->right, s);    
    }
    if(!root->left && !root->right){
        cout << s << "#";
    }
}

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void printPaths(Node* root)
{
    // Code here
    print(root, "");
    cout << endl;
}
