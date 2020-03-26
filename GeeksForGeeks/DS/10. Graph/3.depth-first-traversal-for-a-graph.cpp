// http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct Graph {
	int v;
	list<int> *adj;
};

Graph *newGraph(int v){
	Graph *g = new Graph;
	g->v = v;
	g->adj = new list<int> [v];
}

void addEdge(Graph *g, int src, int dest){
	g->adj[src].push_back(dest);
}

void DFSUtils(Graph *g, bool *visit, int src){
	if(visit[src])
		return;
	visit[src] = true;
	cout<<src<<" ";
	list<int>::iterator iter;
	for(iter = g->adj[src].begin(); iter != g->adj[src].end(); iter++){
		if(!visit[*iter]){
			DFSUtils(g, visit, *iter);
		}
	}
}

void DFS(Graph *g, int src){
	bool *visit;
	visit = new bool[g->v];
	memset(visit, false, sizeof(visit));
	DFSUtils(g, visit, src);
}

void DFSiter(Graph *g, int src){
	bool *visit;
	visit = new bool[g->v];
	memset(visit, false, sizeof(visit));
	visit[src] = true;
	cout<<src<<" ";
	list<int> s;
	list<int>::iterator iter;
	s.push_back(src);
	while(!s.empty()){
		src = s.back();
		iter = g->adj[src].begin();
		while(iter != g->adj[src].end() && visit[*iter])
			iter++;
		if(iter == g->adj[src].end()){
			s.pop_back();
		}
		else{
			s.push_back(*iter);
			visit[*iter] = 1;
			cout<<*iter<<" ";
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

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    DFSiter(g, 2);
    cout<<'\n';
    DFS(g, 2);

	return 0;
}

