// http://www.geeksforgeeks.org/ternary-search-tree

#include <iostream>
using namespace std;

struct node {
	char data;
	node *right, *equal, *left;
	int isEOS;
};

node *newNode(char data){
	node *n = new node;
	n->data = data;
	n->right = NULL;
	n->equal = NULL;
	n->left = NULL;
	n->isEOS = 0;
	return n;
}

void insert(node **root, char *word){
	if(*root == NULL){
		*root = newNode(*word);
		//insert(root, word+1);
		//return;
	}
	if((*root)->data > (*word)){
		insert(&((*root)->left), word);
	}
	else if((*root)->data < (*word)){
		insert(&((*root)->right), word);
	}
	else {
		if(*(word+1))
			insert(&((*root)->equal), word+1);
		else
			(*root)->isEOS = 1;
	}
}

void printArr(char *a){
	int i = 0;
	while(a[i] != '\0'){
		cout<<a[i];
		i++;
	}
	cout<<'\n';
}

void traverseTST(node *root, char *arr, int level){
	if(root == NULL)
		return;
	traverseTST(root->left, arr, level);
	arr[level] = root->data;
	if(root->isEOS){
		arr[level+1] = '\0';
		printArr(arr);
	}
	traverseTST(root->equal, arr, level+1);
	traverseTST(root->right, arr, level);
}

int main(){
	 node *root = NULL;
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    printf("Following is traversal of ternary search tree\n");
    char arr[100];
    traverseTST(root, arr, 0);
	//cout<<root->left->equal->data;
    //printf("\nFollowing are search results for cats, bu and cat respectively\n");
    //searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    //searchTST(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    //searchTST(root, "cat")?  printf("Found\n"): printf("Not Found\n");
	return 0;
}

