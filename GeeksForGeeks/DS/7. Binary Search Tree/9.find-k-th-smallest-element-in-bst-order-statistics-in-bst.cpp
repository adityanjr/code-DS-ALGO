// http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst

#include <iostream>
#include <cstdio>
#include <stack>
#include "bst.h"
using namespace std;

node *k_smallest_element_inorder(node *root, int k){
	if(root == NULL)
		return NULL;
	stack<node*> s;
    int tmp = 1;
	node *ptr = root;
	while(ptr){
		while(ptr){
			s.push(ptr);
			ptr = ptr->left;
        }
		while(!s.empty() && !s.top()->right){
			if(tmp == k)
                return s.top();
            s.pop();
            tmp++;
		}
		if(!s.empty()){
            ptr = s.top();	s.pop();
            if(tmp == k)
                return ptr;
            tmp++;
            ptr = ptr->right;
        }
	}
	return NULL;
}

node *kSmallest(node *root, int k, int *tmp){
    if(root == NULL)
        return NULL;
    node *tmp1 = kSmallest(root->left, k, tmp);
    (*tmp)++;
    if(*tmp == k){
        return root;
    }
    node *tmp2 = kSmallest(root->right, k, tmp);
    if(tmp1)
        return tmp1;
    if(tmp2)
        return tmp2;
}

int main(){
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
	node *root = NULL;
    node *kNode = NULL;

    int k = 5;

    /* Creating the tree given in the above diagram */
    for(int i=0; i<7; i++)
    	root = insert(root, ele[i]);

    //kNode = k_smallest_element_inorder(root, k);
    int tmp = 0;
    kNode = kSmallest(root, k, &tmp);

    if( kNode )
        printf("kth smallest elment for k = %d is %d", k, kNode->data);
    else
        printf("There is no such element");
	return 0;
}
