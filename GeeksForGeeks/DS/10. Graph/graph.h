// Graph Header File

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
	for(int i=0; i<g->v; i++){
		cout<<"vertex :"<<i<<'\n'<<"head-> ";
		node *ptr = g->adj[i].head;
		while(ptr){
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<'\n';
	}
}
