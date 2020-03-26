// http://www.geeksforgeeks.org/detect-cycle-undirected-graph

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct Graph {
	int v;
	list<int> *adj;
};

Graph *newGraph(int v){
	Graph *g = new Graph;
	g->v = v;
	g->adj = new list<int> [v];
	return g;
}

void addEdge(Graph *g, int src, int dest){
	g->adj[src].push_back(dest);
	g->adj[dest].push_back(src);
}

bool isCyclicUtil(Graph *g, bool *visit, int src, int parent){
	visit[src] = 1;
	list<int>::iterator iter;
	for(iter = g->adj[src].begin(); iter != g->adj[src].end(); iter++){
		if(!visit[*iter]){
			if(isCyclicUtil(g, visit, *iter, src));
		}
		else if(parent != *iter){
			return true;
		}
	}
	return false;
}

bool isCyclic(Graph *g){
	bool visit[g->v];
	memset(visit, false, sizeof(visit));
	for(int i=0; i<g->v; i++){
		if(!visit[i]){
			if(isCyclicUtil(g, visit, i, -1))
				return true;
		}
	}
	return false;
}

int main(){
	Graph *g  = newGraph(5);
    addEdge(g, 1, 0);
    addEdge(g, 0, 2);
    addEdge(g, 2, 0);
    addEdge(g, 0, 3);
    addEdge(g, 3, 4);
    isCyclic(g)? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph *g1 = newGraph(3);
    addEdge(g1, 0, 1);
    addEdge(g1, 1, 2);
    isCyclic(g1)? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
	return 0;
}
