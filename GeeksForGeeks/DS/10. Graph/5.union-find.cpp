// http://www.geeksforgeeks.org/union-find

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct edge {
	int src;
	int dest;
};

struct graph{
	int v;
	int *parent;
	list<edge*> adj;
};

graph *newGraph(int v){
	graph *g = new graph;
	g->v = v;
	g->parent = new int[v];
	memset(g->parent, -1, sizeof(int)*v);
	return g;
}

void addEdge(graph *g, int src, int dest){
	edge *e = new edge;
	e->src = src;
	e->dest = dest;
	g->adj.push_back(e);
	return;
}

int find(graph *g, int i){
	if(g->parent[i] == -1){
		return i;
	}
	return find(g, g->parent[i]);
}

void Union(graph *g, int x, int y){
	int xset = find(g, x);
	int yset = find(g, y);
	g->parent[xset] = yset;
}

bool isCyclic(graph *g){
	list<edge*>::iterator iter;
	for(iter = g->adj.begin(); iter != g->adj.end(); iter++){
		int x = find(g, (*iter)->src);
		int y = find(g, (*iter)->dest);
		if(x==y)
			return 1;
		else {
			Union(g, x, y);
		}
	}
	return 0;
}

int main(){
	/* Let us create following graph
         0
        |  \
        |    \
        1-----2 */
    graph* g = newGraph(3);

    // add edge 0-1
    addEdge(g, 0, 1);
    
    // add edge 1-2
    addEdge(g, 1, 2);

    // add edge 0-2
    addEdge(g, 0, 2);

    if (isCyclic(g))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );
	return 0;
}

