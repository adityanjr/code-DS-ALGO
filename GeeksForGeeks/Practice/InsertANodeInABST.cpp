/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of a BST node is as follows:
struct node {
  int data;
  struct node * right, * left;
}; */
/* This function should insert a new node with given data and
   return root of the modified tree  */
struct node* insert(struct node* node, int data)
{
    // Your code here
    struct node* root = new struct node();
    root->data = data;
    
    if(!node){
        return root;
    }
    else if(node->data > data){
        node->left = insert(node->left, data);
    }
    else if(node->data < data){
        node->right = insert(node->right, data);
    }
    return node;
}
