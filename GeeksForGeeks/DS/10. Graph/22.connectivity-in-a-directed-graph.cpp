// http://www.geeksforgeeks.org/connectivity-in-a-directed-graph

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

class Graph {
	int V;
	LI *adj;
	public :
		Graph(int);
		void addEdge(int, int);
		bool isSC();
		void DFS(int src, bool *visit);
		Graph Transpose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
}

Graph Graph::Transpose(){
	Graph gr(V);
	LI::iterator iter;
	for(int i=0; i<V; i++){
		for(iter=adj[i].begin(); iter != adj[i].end(); iter++){
			gr.adj[*iter].PB(i);
		}
	}
	return gr;
}

void Graph::DFS(int src, bool *visit){
	visit[src] = true;
	LI::iterator iter;
	for(iter = adj[src].begin(); iter != adj[src].end(); iter++){
		if(!visit[*iter])
			DFS(*iter, visit);
	}
}

bool Graph::isSC(){
	bool visit[V];
	fill(visit, visit+V, false);
	DFS(0, visit);
	for(int i=0; i<V; i++){
		if(visit[i] == false)
			return false;
	}
	fill(visit, visit+V, false);
	Graph gr = Transpose();
	gr.DFS(0, visit);
	for(int i=0; i<V; i++){
		if(visit[i] == false)
			return false;
	}
	return true;
}

int main(){
	Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";

    return 0;
	return 0;
}

