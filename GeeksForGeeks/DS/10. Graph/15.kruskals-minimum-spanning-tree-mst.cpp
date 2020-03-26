// http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

struct Edge {
	int src, dest, weight;
};

bool compare(Edge a, Edge b){
	return a.weight < b.weight;
}

struct subset {
    int parent;
    int rank;
};

struct Graph {
	int V, E;
	Edge *edge;
};

Graph *createGraph(int V, int E){
	Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edge = new Edge[E];
	return g;
}

int find(subset *sub, int i){
	if(sub[i].parent != i)
		sub[i].parent = find(sub, sub[i].parent);
	return sub[i].parent;
}

void Union(subset *sub, int x, int y){
	int X = find(sub, x);
	int Y = find(sub, y);
	
	if(sub[X].rank < sub[Y].rank){
		sub[X].parent = Y;
	}
	else if(sub[X].rank > sub[Y].rank)
		sub[Y].parent = X;
 	else{
 		sub[Y].parent = X;
 		sub[X].rank++;
 	}
}

void KruskalMST(Graph *g){
	int v = g->V;
	Edge res[v];
	int e=0, i=0;
	sort(g->edge, g->edge+g->E, compare);
	subset sub[v];
	for(int i=0; i<v; i++){
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	
	while(e < v-1){
		Edge next = g->edge[i++];
		int x = find(sub, next.src);
		int y = find(sub, next.dest);
		if(x != y){
			res[e++] = next;
			Union(sub, x, y);
		}
	}
	for(int i=0; i<e; i++){
		printf("%d -- %d == %d\n", res[i].src, res[i].dest, res[i].weight);
	}
}

int main(){
	/* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);
	return 0;
}

