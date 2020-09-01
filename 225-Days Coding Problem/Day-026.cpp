/*
 *  Given a singly linked list and an integer k, remove the kth last element from the list.
 *  k is guaranteed to be smaller than the length of the list.

    The list is very long, so making more than one pass is prohibitively expensive.

    Do this in constant space and in one pass.
 */

/*
 *  Idea is to use two pointer Here & Tortoise , where Tortoise will first move K+1 node ahead and then both will move with
 *  at once , when Tortoise pointer hit null then we have to delete the Here+1 node 
 */
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void print(Node*root){
    Node*temp= root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    puts("");
    return;
}

Node* get_node(int value){
    Node *temp = new Node();
    temp->next = NULL;
    temp->data = value;
    return temp;
}
Node* add(Node *root , int value){
    if(root==NULL){
        return get_node(value);
    }else{
        root->next = add(root->next , value);
        return root;
    }
}
void remove(Node*root , int k ){
    Node* here = root , *tor = root; // tortoise & here 
    ++k;
    while(k--){
        tor = tor->next;
    }
    while(tor!=NULL){
        tor = tor->next;
        here = here->next;
    }
    here->next = here->next->next;
    return;
}
int main(int argc , char *argv[]){
    // write you code here
    Node *root = NULL;
    root = add(root , 10);
    root = add(root , 20);
    root = add(root , 30);
    root = add(root , 40);
    root = add(root , 50);
    root = add(root , 60);
    print(root);
    remove(root , 2); /// will delete 50 
    print(root);
    remove(root,1);
    print(root);
    return 0;
}
