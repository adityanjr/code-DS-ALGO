// http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct Graph {
	int v;
	list<int> *adj;
};

Graph *newGraph(int V){
	Graph *g = new Graph;
	g->v = V;
	g->adj = new list<int> [V];
	return g;
}

void addEdge(Graph *g, int src, int dest){
	g->adj[src].push_back(dest);
}

void BFS(Graph *g, int src){
	bool *visited = new bool[g->v];
	memset(visited, false, sizeof(visited));
	list<int> q;
	list<int>::iterator iter;
	q.push_back(src);
	visited[src] = true;
	while(!q.empty()){
		int s = q.front();
		q.pop_front();
		cout<<s<<" ";
		for(iter = g->adj[s].begin(); iter != g->adj[s].end(); iter++){
			if(!visited[*iter]){
				q.push_back(*iter);
				visited[*iter] = true;
			}
		}
	}
}

int main(){
	Graph *g = newGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    BFS(g, 2);
	return 0;
}

