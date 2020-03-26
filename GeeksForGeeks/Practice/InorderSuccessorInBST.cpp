/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/
/* The below function should return the node which is 
inorder successor of given node x. */
Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    stack<Node*> st;
    
    Node* curr = root;
    
    bool found = false;
    
    while(!st.empty() || curr != NULL){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(found){
                return st.top();
            }
            else if(st.top() == x){
                found = true;
            }
            curr = (st.top())->right;
            st.pop();
        }
    }
    
    return NULL;
}
