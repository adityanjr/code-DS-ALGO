//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// function should print the topView of the binary tree
struct treeNode{
    Node* root;
    int width;
};

void topView(struct Node *root)
{
    // Your code here
    map<int, int> m;
    
    queue<treeNode> q;
    
    int curr = 0;
    
    while(!q.empty() || root){
        if(root){
            if(m.find(curr) == m.end()){
                m[curr] = root->data;
                cout << root->data << " ";
            }
            if(root->left){
                treeNode t;
                t.root = root->left;
                t.width = curr-1;
                q.push(t);
            }
            if(root->right){
                treeNode t;
                t.root = root->right;
                t.width = curr+1;
                q.push(t);
            }
            root = NULL;
        }
        else{
            root = (q.front()).root;
            curr = (q.front()).width;
            q.pop();
        }
    }
    
    // map<int, int> :: iterator it = m.begin();
    
    // while(it != m.end()){
    //     cout << it->first << "->" << it->second << endl;
    //     it++;
    // }
}
