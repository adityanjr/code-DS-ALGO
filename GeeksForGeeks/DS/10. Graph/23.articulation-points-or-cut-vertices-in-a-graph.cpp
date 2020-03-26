// http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph
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
	void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
	public :
		Graph(int);
		void addEdge(int, int);
		void AP();    // prints articulation points
};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
	adj[dest].PB(src);
}

void Graph::APUtil(int u, bool visit[], int disc[], int low[], int parent[], bool ap[]){
	static int time = 0;
	int child = 0;
	visit[u] = 1;
	disc[u]= low[u] = ++time;
	LI::iterator iter;
	for(iter = adj[u].begin(); iter != adj[u].end(); iter++){
		int v = *iter;
		if(!visit[v]){
			child++;
			parent[v] = u;
			APUtil(v, visit, disc, low, parent, ap);

			low[u] = min(low[u], low[v]);

			if(parent[u] == -1 && child > 1)
				ap[u] = 1;
			if(parent[u] != -1 && low[v] >= disc[u])
				ap[u] = 1;
		}
		else if(v != parent[u]) {
			low[u] = min(low[u], disc[v]);
		}
	}
}

void Graph::AP(){
	bool *visit = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V];
	for(int i=0; i<V; i++){
		parent[i] = -1;
		visit[i] = 0;
		ap[i] = 0;
	}
	for(int i=0; i<V; i++){
		if(visit[i] == false){
			APUtil(i, visit, disc, low, parent, ap);
		}
	}
	for(int i=0; i<V; i++){
		if(ap[i])
			cout<<i<<" ";
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
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

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
    g3.AP();
	return 0;
}

