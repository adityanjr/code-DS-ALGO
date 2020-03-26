// http://www.geeksforgeeks.org/union-find/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
#include <cstring>
using namespace std;

struct Edge {
	int src, dest;
};

struct Graph {
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E) {
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

int find(int parent[], int i){
	if(parent[i] == -1)
		return i;
	else
		return find(parent, parent[i]);
}


void _union(int parent[], int x, int y){
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

bool isCycle(Graph* graph){
	int parent[graph->V];
	memset(parent, -1, sizeof(int)*graph->V);
	for (int i = 0; i < graph->E; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		if(x==y)
			return 1;
		_union(parent, x, y);
	}
	return 0;
}

int main(){
	Graph *graph = createGraph(3, 3);
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	graph->edge[2].src = 2;
	graph->edge[2].dest = 0;
	if(isCycle(graph))
		cout<<"cycle";
	else
		cout<<"no-cycle";
	return 0;
}