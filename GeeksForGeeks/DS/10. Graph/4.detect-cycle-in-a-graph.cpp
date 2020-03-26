// http://www.geeksforgeeks.org/detect-cycle-in-a-graph

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
}

bool DFS(Graph *g, bool *visit, bool *recStack, int src){
	if(visit[src]){
		recStack[src] = false;
		return false;
	}
	visit[src] = 1;
	recStack[src] = 1;
	list<int>::iterator iter;
	for(iter = g->adj[src].begin(); iter != g->adj[src].end(); iter++){
		if(!visit[*iter] && DFS(g, visit, recStack, *iter)){
			return true;
		}
		else if(recStack[*iter]){
			return true;
		}
	}
	recStack[src] = false;
	return false;
}

bool isCyclic(Graph *g){
	bool visit[g->v], recStack[g->v];
	memset(visit, false, sizeof(visit));
	memset(recStack, false, sizeof(recStack));
	for(int i=0; i<g->v; i++){
		if(DFS(g, visit, recStack, i)){
			return true;
		}
	}
	return false;
}

int main(){
	Graph *g = newGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);

    if(isCyclic(g))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
	return 0;
}

