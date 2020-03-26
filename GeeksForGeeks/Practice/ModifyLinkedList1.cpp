/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
};
*/
#include <stack>

struct Node* modifyTheList(struct Node *head)
{
//add code here.
    stack<Node*> st;
    
    Node* curr = head;
    
    while(curr){
        st.push(curr);
        curr = curr->next;
    }
    
    curr = head;
    
    while(st.size() != 1){
        curr->data = -((st.top())->data) + (curr->data);
        curr = curr->next;   
        if(curr == st.top()){
            break;
        }
        st.pop();
        if(curr == st.top()){
            break;
        }
    }
    
    return head;
}
