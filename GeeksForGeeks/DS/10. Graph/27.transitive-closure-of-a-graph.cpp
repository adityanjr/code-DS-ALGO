// http://www.geeksforgeeks.org/transitive-closure-of-a-graph

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define V 4

void transitiveClosure(int g[V][V]){
	int cache[V][V];
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			cache[i][j] = g[i][j];
	}
	for(int k=0; k<V; k++){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				cache[i][j] = cache[i][j] || (cache[i][k] && cache[k][j]);
			}
		}
	}
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			cout<<cache[i][j]<<" ";
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
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    // Print the solution
    transitiveClosure(graph);
	return 0;
}

