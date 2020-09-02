/*
 * This problem was asked by Palantir.
 * Typically, an implementation of in-order traversal of a binary 
 * tree has O(h) space complexity, where h is the height of the tree. 
 *
 * Write a program to compute the in-order traversal of a binary tree using O(1) space.
 */

// Basic Idea is to use Morris Algorithm and Pre-requisite for this is Threaded Binary Tree :)

#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
        int value;
        Node *left_Node;
        Node *right_Node;
        Node():value(0),left_Node{nullptr},right_Node{nullptr}{} // constructor 
};
Node* insert(Node* root , int value){
    if(!root){
        root = new Node();
        root->value = value;
        root->left_Node = nullptr;
        root->right_Node= nullptr;
    }else{
        if(root->value < value){
            root->right_Node = insert(root->right_Node , value);
        }else if(root->value > value){
            root->left_Node = insert(root->left_Node , value);
        }
    }
    return root;
}
void print_PreOrder(Node* root){
    if(root==nullptr)
        return;
    print_PreOrder(root->left_Node);
    cout<<root->value<<' ';
    print_PreOrder(root->right_Node);
}


// O(1) Space Complexity Solution (Pre-Order)
void print_PreOrder(Node *root , int &&dummy){
    while(root!=nullptr){
        if(root->left_Node==nullptr){
            cout<<root->value<<' ';
            root = root->right_Node;
        }else{
            Node* predecessor = root->left_Node;
            while(predecessor->right_Node!=nullptr and predecessor->right_Node!=root)/*second condition is to stop revisiting the node*/{
                predecessor = predecessor->right_Node;
            }
            if(predecessor->right_Node==nullptr){
                predecessor->right_Node = root;
                root = root->left_Node;
            }else{
                predecessor->right_Node=nullptr;// removing the link although not required 
                cout<<root->value<<' ';
                root = root->right_Node;
            }
        }
    }
}
int main(int argc , char *argv[]){
    Node *root{nullptr};
    root = insert(root , 10);
    root = insert(root , 5);
    root = insert(root , 30);
    root = insert(root , -2);
    root = insert(root , 6);
    root = insert(root , 40);
    root = insert(root , 2);
    root = insert(root , 8);
    root = insert(root , -1);
    cout<<"Default O(H) PreOrder: ";
    print_PreOrder(root);
    cout<<endl;
    cout<<"Solution O(1) PreOrder: ";
    print_PreOrder(root,1);
    return 0;
}
