// http://www.geeksforgeeks.org/graph-and-its-representations/

#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

struct AdjList {
	node *head;
};

struct Graph {
	int v;
	AdjList *adj;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->next = NULL;
	return n;
}

Graph *newGraph(int V){
	Graph *g = new Graph;
	g->v = V;
	g->adj = new AdjList[V];
	
	for(int i=0; i<V; i++)
		g->adj[i].head = NULL;
	return g;
}

void addEdge(Graph *g, int src, int dest){
	node *n = newNode(dest);
	n->next = g->adj[src].head;
	g->adj[src].head = n;
	
	// If undirected;
	n = newNode(src);
	n->next = g->adj[dest].head;
	g->adj[dest].head = n;
}

void printGraph(Graph *g){
	for(int i=0; i<g->v; 	i++){
		cout<<"vertex :"<<i<<'\n'<<"head-> ";
		node *ptr = g->adj[i].head;
		while(ptr){
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<'\n';
	}
}

int main(){
	int V = 5;
    Graph* graph = newGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
	return 0;
}

