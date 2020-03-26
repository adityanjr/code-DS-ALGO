// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int extractMin(bool *isInc, int *dist, int V) {
	int min = INT_MAX, ind = -1; 
	for(int i=0; i<V; i++){
		if(!isInc[i] && min>dist[i]){
			min = dist[i];
			ind = i;
		}
	}
	return ind;
}

void dijkstra(int **graph, int V, int src){
	int dist[V];
	bool isInc[V];
	memset(isInc, 0, sizeof(isInc));
	memset(isInc, 0, sizeof(isInc));
	fill(dist, dist+V, INT_MAX);
	dist[src] = 0;
	for(int i=0; i<V; i++){
		int ind = extractMin(isInc, dist, V);
		isInc[ind] = 1;
		
		for(int j=0; j<V; j++){
		   if(graph[ind][j] != 0 && !isInc[j] && dist[j] > dist[ind] + graph[ind][j]){
		   	   dist[j] = dist[ind] + graph[ind][j];
		   }
		}
	}
	for(int i=0; i<V; i++){
		cout<<i<<" "<<dist[i]<<'\n';
	}
}

int main(){
	int V=9;
	int a[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
 };
   int **graph;
   for(int i=0; i<V; i++){
       graph[i] = new int[V];
       for(int j=0; j<V; j++){
       	   graph[i][j] = a[i][j];
       }
   }
    dijkstra(graph, V, 0);
}
