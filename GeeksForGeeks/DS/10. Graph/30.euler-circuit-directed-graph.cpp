// http://www.geeksforgeeks.org/euler-circuit-directed-graph

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

class Graph{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    int *in;
public:
    // Constructor and destructor
    Graph(int V);
    ~Graph()   { delete [] adj; delete [] in; }
    void addEdge(int v, int w) { adj[v].push_back(w);  (in[w])++; }
    bool isEulerianCycle();
    bool isSC();
    void DFSUtil(int v, bool visited[]);
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
       in[i] = 0;
}

Graph Graph::getTranspose(){
    Graph g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
            (g.in[v])++;
        }
    }
    return g;
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

bool Graph::isSC(){
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    int n;
    for (n = 0; n < V; n++)
        if (adj[n].size() > 0)
          break;

    DFSUtil(n, visited);

    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
              return false;

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    gr.DFSUtil(n, visited);

    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
             return false;
    return true;
}

bool Graph::isEulerianCycle(){
	if(!isSC())
		return false;
	for(int i=0; i<V; i++){
		if(adj[i].size() != in[i])
			return false;
	}
	return true;
}

int main(){
	// Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if (g.isEulerianCycle())
       cout << "Given directed graph is eulerian \n";
    else
       cout << "Given directed graph is NOT eulerian \n";
	return 0;
}

