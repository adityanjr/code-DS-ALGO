// http://www.geeksforgeeks.org/bipartite-graph/
/* For undirected */

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

bool isBipartiteUtil(bool G[][4], int src, int color, int *visit){
	visit[src] = color;
	for(int i=0; i<4; i++){
		if(G[src][i] && visit[i] == -1){
			if(isBipartiteUtil(G, i, 1-color, visit) == false)
				return false;
		}
		else if (G[src][i] && visit[i] == color){
			return false;
		}
	}
	return true;
}

bool isBipartite(bool G[][4], int src){
	int visit[4];
	memset(visit, -1, sizeof(visit));
	return isBipartiteUtil(G, src, 0, visit);
}

int main(){
	int V = 4;
	bool G[][4] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}

