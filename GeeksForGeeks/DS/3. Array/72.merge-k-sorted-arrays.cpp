// http://www.geeksforgeeks.org/merge-k-sorted-arrays

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include "array.h"

#define N 4

struct node {
	int ind;
	int k;
	int val;
};

bool compare(node *a, node *b){
	return (a->val > b->val);
}

void printHeap(node *a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i].val<<" ";
	}
	cout<<'\n';
}

void mergeKArrays(int a[][N], int k){
	vector<node*> help;
	int out[N*k];
	int i=0;
	for(; i<k; i++){
		node *tmp = new node;
		tmp->ind = 0;
		tmp->k = i;
		tmp->val = a[i][0];
		help.push_back(tmp);
	}
	make_heap(help.begin(), help.end(), compare);
	int j=0;
	while(j < N*k){
		pop_heap(help.begin(), help.end(), compare);
		node *tmp = help.back();
		out[j] = tmp->val;
		j++;
		help.pop_back();
		node *n = new node;
		if(tmp->ind < N-1){
			n->ind = tmp->ind + 1;
			n->k = tmp->k;
			n->val = a[tmp->k][tmp->ind+1];
		}
		else{
			n->ind = -1;
			n->k = -1;
			n->val = INT_MAX;
		}
		help.push_back(n);
		push_heap(help.begin(), help.end(), compare);
	}
	printArray(out, N*k);
}

int main(){
	int arr[][N] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}
    };
    int k = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Merged array is " << endl;
    mergeKArrays(arr, k);
 
    //printHeap(output, n*k);
	return 0;
}

