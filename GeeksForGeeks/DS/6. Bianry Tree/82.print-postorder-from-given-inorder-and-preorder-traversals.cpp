//http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *right, *left;
    node(int d){
        data = d;
        right = left = NULL;
    }
};

int search(int *in, int x, int n){
	for(int i=0; i<n; i++){
		if(in[i] == x)
			return i;
	}
	return -1;
}

void funct(int *in, int *pre, int n){
	if(n <= 0)
		return;
	int root = search(in, pre[0], n);
	funct(in, pre+1, root);
	funct(in+root+1, pre+root+1, n-root-1);
	cout<<pre[0]<<" ";
}

int main(){
	int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] =  {1, 2, 4, 5, 3, 6};
  int n = sizeof(in)/sizeof(in[0]);
  cout << "Postorder traversal " << endl;
  funct(in, pre, n);
}
