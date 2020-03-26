#include <stack>

/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */

/*Complete the function below*/
void kthLargest(Node *root, int k)
{
    //Your code here
    stack<Node*> st;
    
    Node* curr = root;
    
    int count = 0, ans = -1;
    
    while((!st.empty() || curr != NULL) && count < k){
        if(curr){
            st.push(curr);
            curr = curr->right;
        }
        else{
            count++;
            ans = (st.top())->key;
            curr = (st.top())->left;
            st.pop();
        }
    }
    
    cout << ans << endl;
}
