// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define V 9
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

int getMinKey(int *key, bool *inc){
	int idx = -1;
	int val = INT_MAX;
	for(int i=0; i<V; i++){
		if(inc[i] == false && val > key[i]){
			idx = i;
			val = key[i];
		}
	}
	return idx;
}

void dijkstra(int g[V][V], int src){
	bool inc[V];
	int key[V];
	int parent[V];
	fill(inc, inc + V, false);
	fill(key, key+V, INT_MAX);
	fill(parent, parent+V, -1);
	key[src] = 0;
	for(int i=1; i<V; i++){
		int u = getMinKey(key, inc);
		inc[u] = 1;
		for(int v=0; v<V; v++){
			if(inc[v] == false && g[u][v] && key[v] > key[u] + g[u][v]){
				key[v] = key[u] + g[u][v];
				parent[v] = u;
			}
		}
	}
	for(int i=0; i<V; i++){
		cout<<i<<"==>"<<key[i]<<'\n';
	}
}

int main(){
	/* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);
	return 0;
}

