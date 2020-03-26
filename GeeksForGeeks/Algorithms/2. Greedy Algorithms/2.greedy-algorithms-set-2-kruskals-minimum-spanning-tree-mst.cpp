// http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/

#include <iostream>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge {
	int src, dest, weight;
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


int myComp(const void* a, const void* b){
    Edge* a1 = (struct Edge*)a;
    Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph *graph) {
	int V = graph->V;
	Edge res[graph->E];
	qsort(graph->edge, (graph->E), sizeof(graph->edge[0]), myComp);
	int e = 0;
	Subset subset[V];
	for(int i=0; i<graph->V; i++){
		subset[i].parent = i;
		subset[i].rank = 0;
	}
	int i=0;
	while(e < V-1) {
		int x = find(subset, graph->edge[i].src);
		int y = find(subset, graph->edge[i].dest);
		if(x != y) {
			res[e] = graph->edge[i];
			cout<<res[e].src<<"<--"<<res[e].weight<<"-->"<<res[e].dest<<'\n';
			_union(subset, x, y);
			e++;
		}
		i++;
	}
}

int main(){
	Graph *graph = createGraph(4, 5);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

 	// add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    KruskalMST(graph);
	return 0;
}
