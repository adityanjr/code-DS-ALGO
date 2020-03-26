// http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

struct node{
	int dest;
	int weight;
};
typedef list<node> LN;

struct Graph {
	int v;
	LN *adj;
};

Graph *createGraph(int V){
	Graph *g = new Graph;
	g->v = V;
	g->adj = new LN[V];
	return g;
}

void addEdge(Graph *g, int src, int dest, int weight){
	node tmp;
	tmp.dest = dest;
	tmp.weight = weight;
	g->adj[src].PB(tmp);
	tmp.dest = src;
	g->adj[dest].PB(tmp);
}

int getMinKey(int *key, bool *mstSet, int V){
	int m=INT_MAX;
	int k=-1;
	for(int i=0; i<V; i++){
		if(mstSet[i] == false && key[i] < m){
			m = key[i];
			k = i;
		}
	}
	return k;
}

void primMST(Graph *g){
	int v = g->v;
	int key[v];
	int parent[v];
	int weigh[v];
	bool isMst[v];
	fill(key, key+v, INT_MAX);
	fill(isMst, isMst+v, false);
	key[0] = 0;
	parent[0] = -1;
	weigh[0] = -1;
	LN::iterator iter;
	for(int i=0; i<v; i++){
		int u = getMinKey(key, isMst, g->v);
		cout<<u<<" ";
		isMst[u] = 1;
		iter = g->adj[u].begin();
		while(iter != g->adj[u].end()){
			int v = (*iter).dest;
			if(isMst[v] == false && key[v] > (*iter).weight){
				key[v] = (*iter).weight;
				parent[v] = u;
				weigh[v] = (*iter).weight;
			}
			iter++;
		}
	}
	for(int i=1; i<v; i++){
		cout<<parent[i]<<"-->"<<i<<"=="<<weigh[i]<<'\n';
	}
	return;
}

int main(){
	int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    primMST(graph);
	return 0;
}

