// http://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

#include <iostream>
#include <list>
using namespace std;

struct edge {
	int dest;
	int weight;
};

struct Graph {
	int v;
	list<edge*> *adj;
};

Graph *newGraph(int v){
	Graph *g = new Graph;
	g->v = v;
	g->adj = new list<edge*> [v];
	return g;
}

void addEdge(Graph *g, int src, int dest, int weight){
	edge *e = new edge;
	e->dest = dest;
	e->weight = weight;
	g->adj[src].push_back(e);
}

void longestPath(Graph *g, int src){

}

int main(){
	Graph *g = newGraph(6);
    addEdge(g, 0, 1, 5);
    addEdge(g, 0, 2, 3);
    addEdge(g, 1, 3, 6);
    addEdge(g, 1, 2, 2);
    addEdge(g, 2, 4, 4);
    addEdge(g, 2, 5, 2);
    addEdge(g, 2, 3, 7);
    addEdge(g, 3, 5, 1);
    addEdge(g, 3, 4, -1);
    addEdge(g, 4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    longestPath(g, s);
	return 0;
}

