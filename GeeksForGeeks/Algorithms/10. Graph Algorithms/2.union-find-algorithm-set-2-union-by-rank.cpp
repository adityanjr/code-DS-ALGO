// http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

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

struct Subset {
	int parent, rank;
};

Graph* createGraph(int V, int E) {
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

int find(Subset subset[], int i){
	if(subset[i].parent != i)
		subset[i].parent = find(subset, subset[i].parent);
	return subset[i].parent;
}


void _union(Subset subset[], int x, int y){
	int xset = find(subset, x);
	int yset = find(subset, y);
	
	if(subset[xset].rank < subset[yset].rank)
		subset[xset].parent = yset;
	else if(subset[yset].rank < subset[xset].rank)
		subset[yset].parent = xset;
	else {
		subset[yset].parent = xset;
		subset[xset].rank++;
	}
}

bool isCycle(Graph* graph){
	Subset subset[graph->V];
	for(int i=0; i<graph->V; i++){
		subset[i].parent = i;
		subset[i].rank = 0;
	}
	for (int i = 0; i < graph->E; ++i) {
		int x = find(subset, graph->edge[i].src);
		int y = find(subset, graph->edge[i].dest);
		if(x==y) {
			return 1;
		}
		_union(subset, x, y);
	}
	return 0;
}

int main(){
	Graph *graph = createGraph(4, 3);
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	graph->edge[2].src = 2;
	graph->edge[2].dest = 3;
	if(isCycle(graph))
		cout<<"cycle";
	else
		cout<<"no-cycle";
	return 0;
}