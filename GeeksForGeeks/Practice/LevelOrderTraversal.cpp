/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

//You are required to complete this method
void levelOrder(Node* node)
{
    queue<Node*> q;
    queue<int> lev;
    
    int level = 1;
    
    q.push(node);
    lev.push(1);
    
    do{
        Node* curr = q.front();
        int currLevel = lev.front();
        
        if(level < currLevel){
            cout << "$ ";
            level = currLevel;
        }
        
        cout << curr->data << " ";
        
        lev.pop();
        q.pop();
        
        if(curr->left != NULL){
            q.push(curr->left);
            lev.push(level+1);
        }
        if(curr->right != NULL){
            q.push(curr->right);
            lev.push(level+1);
        }
    }while(!q.empty());

    cout << "$";
}
