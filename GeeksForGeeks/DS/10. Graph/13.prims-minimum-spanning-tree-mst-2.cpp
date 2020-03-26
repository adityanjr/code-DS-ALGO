// http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define V 5

int minKey(int *key, bool *mstSet){
	int m=INT_MAX;
	int k=-1;
	for(int i=0; i<V; i++){
		if(mstSet[i] == false && key[i] < m){
			m = key[i];
			k = i;
		}
	}
	return k;
}

void primMST(int graph[V][V]){
	int parent[V]; // Array to store constructed MST
    int key[V];   // Key values used to pick minimum weight edge in cut
    bool mstSet[V];
    fill(key, key+V, INT_MAX);
    fill(parent, parent+V, -1);
    fill(mstSet, mstSet+V, 0);
    key[0] = 0;
	for(int i=0; i<V-1; i++){
		int u = minKey(key, mstSet);
		cout<<u<<" ";
		mstSet[u] = true;
		for(int j=0; j<V; j++){
			if(graph[u][j] && mstSet[j] == false  && key[j] > graph[u][j]){
				key[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}
	for(int i=1; i<V; i++){
		cout<<parent[i]<<"-->"<<i<<"=="<<graph[parent[i]][i]<<'\n';
	}
}

int main(){
	/* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);
	return 0;
}

