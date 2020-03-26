// http://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define V 5

int countwalks(int g[V][V], int src, int dest, int k){
	if(k==0 && src==dest)
		return 1;
	if(k<=0)
		return 0;
	int count = 0;
	for(int i=0; i<V; i++){
		if(g[src][i])
			count += countwalks(g, i, dest, k-1);
	}
	return count;
}

int main(){
	/* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countwalks(graph, u, v, k);
	return 0;
}

