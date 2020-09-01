/*
 * This problem was asked by Google.  
 *
 * Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
 * and deserialize(s), which deserializes the string back into the tree.  
 * For example, given the following Node class
 *
 * class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
 *
 *
 * The following test should be passed
 *
 * node = Node('root', Node('left', Node('left.left')), Node('right'))
 * assert deserialize(serialize(node)).left.left.val == 'left.left'
 *
 *
 */


#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        string value;
        Node *left = nullptr;
        Node *right = nullptr;
};
string serialize(Node *root){
    if(root==nullptr){
        return "&"; // separator & represent that current Node is empty 
    }
    return root->value+"/"+serialize(root->left)+"/"+serialize(root->right); // here / represent that data of current is completely processed
}

Node * de_serialize(string &s, int &index){
    string temp = "";
    for(;(index<(int)s.size()) && (s[index]!='&' && s[index]!='/');++index){
        temp+=(s[index]);
    }
    if(temp=="&" || temp==""){
        return nullptr;
    }
    Node *t = new Node();
    t->value= temp;
    index+=1;
    t->left = de_serialize(s , index);
    index+=1;
    t->right = de_serialize(s,index);
    return t;
}

void pre_order(Node *R){
    if(R==nullptr){
        return ;
    }
    cout<<R->value<<endl;
    pre_order(R->left);
    pre_order(R->right);
}
int main(void){
    Node *root = new Node();
    root->value = "root";
    Node *l1 = new Node();
    l1->value = "left";
    Node *ll1 = new Node();
    ll1->value = "left.left";
    Node *r1 = new Node();
    r1->value = "right";

    root->left = l1;
    root->right = r1;
    l1->left = ll1;

    string s = serialize(root);

    // de-serializing the string into binary tree 
    
    int index = 0;
    Node *R = de_serialize(s,index);
    pre_order(R); // pre-order on de-serialized tree 
    assert(R->left->left->value=="left.left"); // condition from google 
    return 0;
}
