// http://www.geeksforgeeks.org/eulerian-path-and-circuit

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

class Graph {
	int V;
	LI *adj;
	void DFSUtil(int v, bool visited[]);
	public :
		Graph(int);
		void addEdge(int, int);
		bool isConnected();
		int isEulerian();    // prints articulation points
};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
	adj[dest].PB(src);
}

void Graph::DFSUtil(int u, bool *visit){
	visit[u] = 1;
	LI::iterator iter;
	for(iter = adj[u].begin(); iter != adj[u].end(); iter++){
		int v = *iter;
		if(!visit[v]){
			DFSUtil(v, visit);
		}
	}
}

bool Graph::isConnected(){
	bool visit[V];
	fill(visit, visit+V, false);
	int i;
	for(i=0; i<V; i++){
		if(adj[i].size() != 0)
			break;
	}
	if(i==V)
		return true;
	DFSUtil(i, visit);
	for(int i=0; i<V; i++){
		if(visit[i] == false && adj[i].size()>0)
			return false;
	}
	return true;
}

int Graph::isEulerian(){
	if(!isConnected())
		return 0;
		
	int odd = 0;
	for(int i=0; i<V; i++){
		if(adj[i].size() & 1)
			odd++;
	}
	 // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}

void test(Graph &g){
    int res = g.isEulerian();
    if (res == 0)
        cout << "Graph is not Eulerian\n";
    else if (res == 1)
        cout << "Graph has a Euler path\n";
    else
        cout << "Graph has a Euler cycle\n";
}

int main(){
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);

    // Let us create a graph with all veritces
    // with zero degree
    Graph g5(3);
    test(g5);
	return 0;
}

