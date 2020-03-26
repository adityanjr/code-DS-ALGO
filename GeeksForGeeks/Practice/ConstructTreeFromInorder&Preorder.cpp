/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int find(int in[], int key, int start, int end){
    for(int i = start; i <= end; i++){
        if(in[i] == key){
            return i;
        }
    }
    
    return -1;
}

Node* make(int in[], int pre[], int inS, int inE, int& i){
    if(inS > inE){
        return NULL;
    }
    
    int index = find(in, pre[i], inS, inE);
    
    Node* root = new Node();
    root->data = pre[i];
    i++;
    root->left = make(in, pre, inS, index-1, i);
    root->right = make(in, pre, index+1, inE, i);
    
    return root;
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
//add code here.;
    int index = 0;
    return make(in, pre, inStrt, inEnd, index);
}
