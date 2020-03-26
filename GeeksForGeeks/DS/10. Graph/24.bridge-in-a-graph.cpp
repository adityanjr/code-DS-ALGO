// http://www.geeksforgeeks.org/bridge-in-a-graph/
/*Not completely understand*/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

class Graph {
	int V;
	LI *adj;
	void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
	public :
		Graph(int);
		void addEdge(int, int);
		void bridge();    // prints articulation points
};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
	adj[dest].PB(src);
}

void Graph::bridgeUtil(int u, bool visit[], int disc[], int low[], int parent[]){
	static int time = 0;
	visit[u] = 1;
	disc[u]= low[u] = ++time;
	LI::iterator iter;
	for(iter = adj[u].begin(); iter != adj[u].end(); iter++){
		int v = *iter;
		if(!visit[v]){
			parent[v] = u;
			bridgeUtil(v, visit, disc, low, parent);

			low[u] = min(low[u], low[v]);

			if(low[v] > disc[u])
				cout<<u<<"->"<<v<<'\n';
		}
		else if(v != parent[u]) {
			low[u] = min(low[u], disc[v]);
		}
	}
}

void Graph::bridge(){
	bool *visit = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	for(int i=0; i<V; i++){
		parent[i] = -1;
		visit[i] = 0;
	}
	for(int i=0; i<V; i++){
		if(visit[i] == false){
			bridgeUtil(i, visit, disc, low, parent);
		}
	}
}

int main(){
	cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
	return 0;
}

