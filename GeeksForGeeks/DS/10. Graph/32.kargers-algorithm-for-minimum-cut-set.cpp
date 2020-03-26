// http://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-1-introduction-and-implementation
/*Not completely*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest;
};

typedef list<Edge> LE;

struct subset{
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
    g->edge = new Edge[V];
    return g;
}

int find(subset S[], int i){
    if(S[i].parent != i)
        S[i].parent = find(S, S[i].parent);
    return S[i].parent;
}

void Union(subset S[], int x, int y){
    int X = find(S, x);
    int Y = find(S, y);
    if(S[X].rank < S[Y].rank){
        S[X].parent = Y;
    }
    else if(S[X].rank > S[Y].rank)
        S[Y].parent = X;
    else {
        S[Y].parent = X;
        S[X].rank++;
    }
}

int kargerMinCut(Graph *g){
    int v =g->V;
    int e = g->E;
    subset S[v];
    for(int i=0; i<v; i++){
        S[i].parent = i;
        S[i].rank = 0;
    }
    int vertices = v;
    while(vertices > 2){
        int i = rand()%e;
        int subset1 = find(S, g->edge[i].src);
        int subset2 = find(S, g->edge[i].dest);

       // If two corners belong to same subset,
       // then no point considering this edge
       if (subset1 == subset2)
         continue;

       // Else contract the edge (or combine the
       // corners of edge into one vertex)
       else
       {
          printf("Contracting edge %d-%d\n", g->edge[i].src, g->edge[i].dest);
          vertices--;
          Union(S, subset1, subset2);
       }
    }
    int cutedges = 0;
    for (int i=0; i<e; i++){
        int subset1 = find(S, g->edge[i].src);
        int subset2 = find(S, g->edge[i].dest);
        if (subset1 != subset2)
          cutedges++;
    }

    return cutedges;
}

int main(){
    /* Let us create following unweighted graph
        0------1
        | \    |ĵ
        |   \  |
        |     \|
        2------3   */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;

    // Use a different seed value for every run.
    srand(time(NULL));

    printf("\nCut found by Karger's randomized algo is %d\n",
           kargerMinCut(graph));

    return 0;
}
