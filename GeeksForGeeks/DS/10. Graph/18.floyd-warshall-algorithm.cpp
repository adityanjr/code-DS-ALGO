// http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define V 4
#define INF INT_MAX

void floydWarshell(int g[V][V]){
	int dist[V][V];
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			dist[i][j] = g[i][j];
	}
	for(int k=0; k<V; k++){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
	/* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floydWarshell(graph);
	return 0;
}

