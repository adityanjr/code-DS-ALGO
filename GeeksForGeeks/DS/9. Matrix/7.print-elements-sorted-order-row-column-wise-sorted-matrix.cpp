// http://www.geeksforgeeks.org/print-elements-sorted-order-row-column-wise-sorted-matrix

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int data;
	int idx;
	int k;
};

bool compare(node *a, node *b){
	return (a->data > b->data);
}
/*
void printMatrix(int **a, int R, int C){
    for(int i=0; i<R; i++){
    	for(int j=0; j<C; j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<'\n';
	}
}*/

void printSorted(int **a, int R, int C){
	vector<node*> v;
	for(int i=0; i<R; i++){
		node *tmp = new node;
		tmp->data = a[i][0];
		tmp->idx = 0;
		tmp->k = i;
		v.push_back(tmp);
	}
	make_heap(v.begin(), v.end(), compare);

	while(!v.empty()){
		pop_heap(v.begin(), v.end(), compare);
		node *tmp = v[v.size()-1];
		v.pop_back();
		cout<<tmp->data<<" ";
		if(tmp->idx < C-1){
			node *ptr = new node;
			ptr->data = a[tmp->k][tmp->idx+1];
			ptr->k = tmp->k;
			ptr->idx = tmp->idx+1;
			v.push_back(ptr);
			push_heap(v.begin(), v.end(), compare);
		}
	}
}

int main(){
	int N = 4;
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
	int **arr;
	arr = new int*[N];
	for(int i=0; i<N; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++)
			arr[i][j] = mat[i][j];
	}
  printSorted(arr, N, N);
	return 0;
}

