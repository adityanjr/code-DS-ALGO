// http://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals
/*To Do*/

#include <iostream>
#include <algorithm>
#include "bt.h"

node *buildTree(int *in, int *level, int start, int end, int n){
	if(n<=0 || start>end)
		return NULL;
	node *root = newNode(level[0]);
	if(n == 1)
		return root;
	int i = find(in+start, in+end+1, level[0]) - in;

	int nL = i;
	int nR = n-(i+1);
	int levelL[nL];
	int levelR[nR];
	int l=0, r=0;
	for(int j=1; j<n; j++){
		bool flag = false;
		for(int k=0; k<i; k++){
			if(level[j] == in[k])
				flag = true;
				break;
		}
		if(flag){
			levelL[l] = level[j];
			l++;
		}
		else
			levelR[r] = level[j];
			r++;
	}
	cout<<start<<" "<<i<<" "<<end<<" "<<nL<<" "<<nR<<'\n';
	node *le = buildTree(in, levelL, start, i-1, nL);
	node *ri = buildTree(in, levelR, i+1, end, nR);
	root->left = le;
	root->right = ri;
	return root;
}

int main(){
	int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    node *root = buildTree(in, level, 0, n - 1, n);

    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    //printInorder(root);
	return 0;
}

