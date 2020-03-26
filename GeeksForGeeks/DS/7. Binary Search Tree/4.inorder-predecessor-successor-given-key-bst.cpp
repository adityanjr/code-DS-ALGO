// http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst

#include <iostream>
#include "bst.h"

void findPreSuc(node *root, node* &pre, node* &suc, int key){
	 if(root == NULL)
         return;
	 if(root->data < key && (!pre || pre->data < root->data))
  	     pre = root;
 	 if(root->data > key && (!suc || suc->data > root->data))
  	     suc = root;
		 
	 if(key < root->data)
		 findPreSuc(root->left, pre, suc, key);
	 else if(key > root->data)
	 	 findPreSuc(root->right, pre, suc, key);
	 else {
	 	 findPreSuc(root->left, pre, suc, key);
	 	 findPreSuc(root->right, pre, suc, key);
     }	 
}

int main(){
	 int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
      getchar();
    return 0;
}
