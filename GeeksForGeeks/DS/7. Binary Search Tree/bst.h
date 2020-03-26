//Binary Search Tree Header File

//#include <iosteam>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *newNode(int data){
	 node *n = new node;
	 n->data = data;
	 n->left = n->right = NULL;
	 return n;
}

void printInorder(node *root){
	 if(root == NULL)
	     return;
	 printInorder(root->left);
	 cout<<root->data<<" ";
	 printInorder(root->right);
}

node *insert(node *root, int data){
     if(root == NULL)
 		  root = newNode(data);
    else{
		 if(root->data > data){
		     root->left = insert(root->left, data);		  	 
   		 }
   		 else
   		 	 root->right = insert(root->right, data);
    }
    return root;
}
