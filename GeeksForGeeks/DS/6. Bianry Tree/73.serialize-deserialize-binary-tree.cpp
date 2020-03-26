// http://www.geeksforgeeks.org/serialize-deserialize-binary-tree

#include <iostream>
#include "bt.h"

string serialize(node *root){
	if(root == NULL)
		return "-1 ";
	string res = to_string(root->data) + " ";
	res = res + serialize(root->left) + serialize(root->right);
	return res;
}

void deSerialize(node **root, string *fp){
	if((*fp).length()<1)
		return;
	int i = (*fp).find(" ");
	int data = stoi((*fp).substr(0, i));
	*fp = (*fp).substr(i+1);
	if(data == -1)
		return;
	node *n = newNode(data);

	if(*root == NULL)
		*root = n;
	deSerialize(&(*root)->left, fp);
	deSerialize(&(*root)->right, fp);
}

int main(){
	node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    string fp = serialize(root);
    cout<<fp<<'\n';

    // Let us deserialize the storeed tree into root1
    node *root1 = NULL;
    deSerialize(&root1, &fp);

    //printf("Inorder Traversal of the tree constructed from file:\n");
    printInorder(root1);
	return 0;
}

