// http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph

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
		bool isReachable(int src, int dest);
};

Graph::Graph(int V){
	this->V = V;
	adj = new LI[V];
}

void Graph::addEdge(int src, int dest){
	adj[src].PB(dest);
}

bool Graph::isReachable(int src, int dest){
	if(src == dest)
		return true;
	bool visit[V];
	fill(visit, visit+V, false);
	QI q;
	q.push(src);
	LI::iterator iter;
	visit[src] = true;
	while(!q.empty()){
		int u = q.front();  q.pop();
		iter = adj[u].begin();
		for(;iter != adj[u].end(); iter++){
			if(*iter == dest)
				return true;
			if(!visit[*iter]){
				visit[*iter] = 1;
				q.push(*iter);
			}
		}
	}
	return false;
}

int main(){
	// Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;

    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;

	return 0;
}

