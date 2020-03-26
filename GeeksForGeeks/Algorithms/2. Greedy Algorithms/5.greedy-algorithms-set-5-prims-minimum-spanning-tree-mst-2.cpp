//http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int minKey(int *key, int *isMst, int n){
	int val = INT_MAX;
	int ind = -1;
	for(int i=0; i<n; i++){
		if(!isMst[i] && val>key[i]){
			val = key[i];
			ind = i;
		}
	}
	return ind;
}

void primMST(int **graph, int N){
	int key[N];
	int isMst[N];
	int parent[N];
	fill(key, key + N, INT_MAX);
	memset(isMst, 0, sizeof(isMst));
	memset(parent, -1, sizeof(parent));
	key[0] = 0;
	isMst[0] = 0;
	parent[0] = -1;
	int included = 0;
	for(int inc=0; inc < N-1; inc++) {
		int ind = minKey(key, isMst, N);
		isMst[ind] = 1;
		for(int i=0; i<N; i++){
			if(graph[ind][i] && isMst[i]==false && key[i] > graph[ind][i]){
				key[i] = graph[ind][i];
				parent[i] = ind;
			}
		}
	}
	for(int i=0; i<N; i++){
		if(parent[i] != -1){
			cout<<i<<"<-->"<<parent[i]<<"----"<<graph[i][parent[i]]<<'\n';
		}
	}
}

int main() {
	int **graph;
	int N=5;
	int arr[5][5] = {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}
    		};
	for(int i=0; i<N; i++){
		graph[i] = new int[N];
		for(int j=0; j<N; j++){
			graph[i][j] = arr[i][j];
		}
	}
    // Print the solution
    primMST(graph, 5);
}
