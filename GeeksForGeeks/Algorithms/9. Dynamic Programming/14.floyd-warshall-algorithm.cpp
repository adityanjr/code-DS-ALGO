// http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm

#include <iostream>
#include <cstdio>
using namespace std;

#define INF 10000000

void floydWarshell(int **graph, int V){
	int **cache = new int*[V];
	for(int i=0; i<V; i++){
		cache[i] = new int[V];
		for(int j=0; j<V; j++){
			cache[i][j] = graph[i][j];
		}
	}
	for(int k=0; k<V; k++){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(cache[i][k] + cache[k][j] < cache[i][j])
					cache[i][j] = cache[i][k] + cache[k][j];
			}
		}
	}
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout<<cache[i][j]<<" ";
		}
		cout<<'\n';
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
	int V = 4;
    int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
    };
	int **arr = new int*[V];
	for(int i=0; i<V; i++){
		arr[i] = new int[V];
		for(int j=0; j<V; j++){
			arr[i][j] = graph[i][j];
		}
		
	}
    // Print the solution
    floydWarshell(arr, V);
	return 0;
}

