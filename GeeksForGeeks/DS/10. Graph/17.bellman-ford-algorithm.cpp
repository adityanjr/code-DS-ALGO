// http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
/* Directed */

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	Edge *edge;
};

Graph *createGraph(int V, int E){
	Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edge = new Edge[E];
	return g;
}

void BellmanFord(Graph *g, int src){
	int v = g->V;
	int e = g->E;
	int key[v];
	fill(key, key+v, INT_MAX);
	key[src] = 0;
	
	for(int i=1; i<v; i++){
		for(int j=0; j<e; j++){
			int u = g->edge[j].src;
			int v = g->edge[j].dest;
			int weight = g->edge[j].weight;
			if(key[u] != INT_MAX && key[u] + weight < key[v])
				key[v] = key[u] + weight;
		}
	}
	
	for(int j=0; j<e; j++){
		int u = g->edge[j].src;
		int v = g->edge[j].dest;
		int weight = g->edge[j].weight;
		if(key[u] != INT_MAX && key[u] + weight < key[v])
			cout<<"Graph contain -ve weight cycle"<<'\n';
  	}
  	printf("Vertex   Distance from Source\n");
    for (int i = 0; i < v; ++i)
        printf("%d \t\t %d\n", i, key[i]);
}

int main(){
	/* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);
	return 0;
}

