// http://www.geeksforgeeks.org/find-the-minimum-cost-to-reach-a-destination-where-every-station-is-connected-in-one-direction

#include <bits/stdc++.h>
using namespace std;

#define N 4
#define INF INT_MAX

int minCost(int cost[N][N]){
	int cache[N];   //Only starting point is 0 that's why 1D
	fill(cache, cache+N, INT_MAX);
	cache[0] = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(cache[j] > cache[i] + cost[i][j])
				cache[j] = cache[i] + cost[i][j];
		}
	}
	return cache[N-1];
}

int main() {
	int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to reach station "
          << N << " is " << minCost(cost);
}
