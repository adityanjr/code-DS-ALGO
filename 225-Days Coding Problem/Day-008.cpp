/*
 * This problem was asked by Google.  
 *
 * A unival tree (which stands for "universal value") is a tree where 
 * all nodes under it have the same value.  
 *
 * Given the root to a binary tree, count the number of unival subtrees.  
 * For example, the following tree has 5 unival subtrees: 
 * 
           0
          / \
         1   0
            / \
           1   0
          / \
         1   1
 *
 * 
 */

#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node*left; 
    Node*right;
    int data;
    Node():left(nullptr),right(nullptr),data(0){}
};
int counter{};
bool unival(Node*root){
    if(root==nullptr){
        return true;
    }
    bool ok = true; // let this be a unival tree 
    bool left = unival(root->left);
    bool right = unival(root->right);
    ok &=left; 
    ok &=right;
    if(!ok)/*if either left or right is not uni-value*/{
        return ok;
    }
    if(root->left && root->left->data !=root->data){
        return false;
    }
    if(root->right && root->right->data !=root->data){
        return false;
    }
    counter++;
    return true;
}
int main(void){
    // tree formation 
    Node*root = new Node();
    root->data = 0;
    Node*n1  = new Node();
    n1->left = nullptr;
    n1->right= nullptr;
    n1->data = 1;
    root->left = n1;

    Node*n2 = new Node();
    n2->data = 0;
    root->right= n2;

    Node*n3 = new Node(); 
    Node*n4 = new Node();
    n2->right = n3; n3->data = 0;
    n2->left = n4; n4->data = 1;
    Node*n5 = new Node();
    Node*n6 = new Node();
    n4->right = n5;
    n4->left = n6;
    n5->data = 1;
    n6->data = 1;
    // counting uni-value trees 
    unival(root);
    cout<<counter<<endl;
    return 0;
}
