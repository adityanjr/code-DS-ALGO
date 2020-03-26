/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
    if(!a && !b){
        return 1;
    }
    else if(!a || !b){
        return 0;
    }
    else if(a->data != b->data){
        return 0;
    }
    return areMirror(a->left, b->right) & areMirror(a->right, b->left);
}

