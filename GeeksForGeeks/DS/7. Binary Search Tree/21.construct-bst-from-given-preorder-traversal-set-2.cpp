// http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *right, *left;
    node(int d){
        data = d;
        right = left = NULL;
    }
};

node *newNode(int d){
    return new node(d);
}

void inorder(node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node *constructTree(int *arr, int n){
    node *root = newNode(arr[0]);
    if(n==1)
        return root;
    stack<node*> s;
    s.push(root);
    int i=1;
    while(i < n){
        node *ptr = NULL;// = s.top();    s.pop();
        while(!s.empty() && s.top()->data < arr[i]){
            ptr = s.top();  s.pop();
        }
        if(ptr == NULL){
            if(!s.empty()){
                if(s.top()->data <= arr[i]){
                    s.top()->right = newNode(arr[i]);
                    s.push(s.top()->right);
                }
                else {
                    s.top()->left = newNode(arr[i]);
                    s.push(s.top()->left);
                }
                i++;
            }
        }
        else {
            if(ptr->data <= arr[i]){
                ptr->right = newNode(arr[i]);
                s.push(ptr->right);
                i++;
            }
        }
    }
    return root;
}

int main() {
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    node *root = constructTree(pre, size);

    printf("Inorder traversal of the constructed tree: \n");
    inorder(root);
	return 0;
}
