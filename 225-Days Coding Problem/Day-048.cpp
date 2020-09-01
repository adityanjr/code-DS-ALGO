/*
   This problem was asked by Google.

   Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

   For example, given the following preorder traversal:

   [a, b, d, e, c, f, g]

   And the following inorder traversal:

   [d, b, e, a, f, c, g]

   You should return the following tree:

        a
       / \
      b   c
     / \ / \
    d  e f  g

 */
#include <bits/stdc++.h>
using namespace std;
struct Node{
    char value;
    Node* leftNode;
    Node* rightNode;
};
Node* getNewNode(int x){
    Node* temp = new Node(); 
    temp->value = x;
    temp->leftNode = nullptr;
    temp->rightNode = nullptr;
    return temp;
}
int preOrderIndex;
Node* formTree(vector<char>&preorder , vector<char>&inorder , int start , int end , unordered_map<char,int>&index){
    if(start>end){
        return nullptr;
    }

    Node* root = getNewNode(preorder[ preOrderIndex ]); // set the root
    if(start==end){
        preOrderIndex++;
        return root;
    }
    // now we have to look for next root which we can find with index
    int middle = index[ preorder[ preOrderIndex++ ] ];

    root->leftNode = formTree(preorder , inorder , start , middle-1 , index);
    root->rightNode = formTree(preorder , inorder , middle+1 , end , index);

    return root;
}
Node* binaryTree(vector<char>&preorder , vector<char>&inorder) {
    preOrderIndex = 0;
    unordered_map<char , int>index; // for fast search 
    for( int i{}; i < (int) inorder.size() ; ++i ){
        index[ inorder[ i ] ] = i;
    }
    return formTree(preorder , inorder, 0, (int)inorder.size()-1 , index);
}

void preOrder(Node*root){
    if(root==nullptr){
        return;
    }
    cout<<root->value<<' ';
    preOrder(root->leftNode);
    preOrder(root->rightNode);
    return;
}

int main(void){
    vector<char> preorder { 'a', 'b', 'd', 'e', 'c', 'f', 'g' };
    vector<char> inorder { 'd', 'b', 'e', 'a', 'f', 'c', 'g' };
    Node* root = binaryTree(preorder , inorder);
    preOrder(root);
    cout<<'\n'; 
    return 0;
}
