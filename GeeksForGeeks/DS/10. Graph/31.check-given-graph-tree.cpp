// http://geeksquiz.com/check-given-graph-tree/

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
    void addEdge(int v, int w);
    bool isTree();
    bool isCycle(int src, bool *visit, int);
    void DFSUtil(int v, bool visited[]);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
       in[i] = 0;
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}

bool Graph::isCycle(int src, bool *visit, int parent){
	visit[src] = 1;
	LI::iterator iter = adj[src].begin();
	for(; iter != adj[src].end(); iter++){
		if(!visit[*iter]){
			if(isCycle(*iter, visit, src))
				return true;
		}
		else if(*iter != parent){
			return true;
		}
	}
	return false;
}

bool Graph::isTree(){
	bool visit[V];
	fill(visit, visit+V, false);
	if(isCycle(0, visit, -1)){
		return false;
	}
	for(int i=0; i<V; i++){
		if(visit[i] == false){
			return false;
		}
	}
	return true;
}

int main(){
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
	return 0;
}

