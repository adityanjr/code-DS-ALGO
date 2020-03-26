// http://www.geeksforgeeks.org/topological-sorting

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define P push
typedef stack<int> SI;

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
	g->adj[src].PB(dest);
}

void topologicalSortUtil(Graph *g, bool *visit, int src, SI &s){
	visit[src] = 1;
	list<int>::iterator iter = g->adj[src].begin();
	for(; iter != g->adj[src].end(); iter++){
		if(!visit[*iter])
			topologicalSortUtil(g, visit, *iter, s);
	}
	s.P(src);
}

void topologicalSort(Graph *g){
	SI s;
	int v = g->v;
	bool *visit = new bool[v];
	memset(visit, false, sizeof(visit));
	for(int i=0; i<v; i++){
		if(!visit[i])
			topologicalSortUtil(g, visit, i, s);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
	// Create a graph given in the above diagram
    Graph *g = newGraph(6);
    addEdge(g, 5, 2);
    addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(g);
	return 0;
}

