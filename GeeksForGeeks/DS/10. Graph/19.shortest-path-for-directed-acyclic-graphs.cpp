// http://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

struct node {
	int v;
	int weight;
};

typedef list<node> LN;

class Graph {
	int V;
	LN *adj;
	void topologicalSort(int, bool *, SI &);
	public:
		Graph(int);
		void addEdge(int u, int v, int weight);
		void shortestPath(int s);
};

Graph::Graph(int v){
	this->V = v;
	adj = new LN[v];
}

void Graph::addEdge(int src, int dest, int weight){
	node tmp;
	tmp.v = dest;
	tmp.weight = weight;
	adj[src].PB(tmp);
}

void Graph::topologicalSort(int src, bool *visit, SI &s){
	visit[src] = true;
	LN::iterator iter = adj[src].begin();
	while(iter != adj[src].end()){
		if(!visit[(*iter).v]){
			topologicalSort((*iter).v, visit, s);
		}
		iter++;
	}
	s.push(src);
}

void Graph::shortestPath(int src){
	SI s;
	int dist[V];
	bool visit[V];
	fill(visit, visit + V, false);
	fill(dist, dist+V, INT_MAX);
	for(int i=0; i<V; i++){
		if(!visit[i])
			topologicalSort(i, visit, s);
	}
	dist[src] = 0;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		LN::iterator iter = adj[u].begin();
		while(iter != adj[u].end()){
			int v = (*iter).v;
			if(dist[u] != INT_MAX && dist[v] > dist[u] + (*iter).weight)
				dist[v] = dist[u] + (*iter).weight;
			iter++;
		}
	}
	for(int i=0; i<V; i++){
		cout<<i<<" "<<dist[i]<<'\n';
	}
}

int main(){
	// Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are shortest distances from source " << s <<" \n";
    g.shortestPath(s);
	return 0;
}

