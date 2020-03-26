/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include <stack>
#include <vector>
#include <algorithm>
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
    stack<Node*> st;
    
    Node* curr = root;
    vector<Node*> temp;
    
    while(!st.empty() || curr){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp.push_back(st.top());
            // cout << (st.top())->key << " ";
            curr = (st.top())->right;
            st.pop();
        }
    }
    
    for(int i = 0; i < temp.size(); i++){
        if(temp[i]->key == key){
            if(i-1 >= 0){
                pre = temp[i-1];
            }
            if(i+1 < temp.size()){
                suc = temp[i+1];    
            }
            return;
        }
        else if(temp[i]->key > key){
            if(i-1 >= 0){
                pre = temp[i-1];
            }
            suc = temp[i];    
            return;
        }
    }
    
    pre = temp[temp.size()-1];
}
