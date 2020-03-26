// http://www.geeksforgeeks.org/strongly-connected-components

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

class Graph {
	int V;
	LI *adj;
	void DFSUtil(int v, bool visited[], SI &s);
	void printDFS(int u, bool *visit);
	public :
		Graph(int);
		void addEdge(int, int);
		void printSCCs();
		Graph transpose();

};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
}

Graph Graph::transpose(){
	Graph gr(V);
	LI::iterator iter;
	for(int i=0; i<V; i++){
		for(iter = adj[i].begin(); iter != adj[i].end(); iter++){
			gr.adj[*iter].PB(i);
		}
	}
	return gr;
}

void Graph::DFSUtil(int src, bool *visit, SI &s){
	visit[src] = 1;
	LI::iterator iter = adj[src].begin();
	for(; iter != adj[src].end(); iter++){
		if(!visit[*iter])
			DFSUtil(*iter, visit, s);
	}
	s.push(src);
}

void Graph::printDFS(int u, bool *visit){
	visit[u] = 1;
	cout<<u<<" ";
	LI::iterator iter = adj[u].begin();
	for(; iter != adj[u].end(); iter++){
		if(!visit[*iter])
			printDFS(*iter, visit);
	}
}

void Graph::printSCCs(){
	bool visit[V];
	fill(visit, visit+V, false);
	SI s;
	for(int i=0; i<V; i++){
		if(!visit[i])
			DFSUtil(i, visit, s);
	}
	Graph gr = transpose();
	fill(visit, visit+V, false);
	while(!s.empty()){
		int u = s.top();    s.pop();
		if(visit[u])
			continue;
		gr.printDFS(u, visit);
		cout<<'\n';
	}
}

int main(){
	 Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in given graph \n";
    g.printSCCs();
	return 0;
}

