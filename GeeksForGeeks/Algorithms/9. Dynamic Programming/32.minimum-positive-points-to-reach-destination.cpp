// http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination

#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int minInitialPoints(int p[R][C]){
	int cache[R][C];
	cache[R-1][C-1] = p[R-1][C-1] > 0 ? 1 : -p[R-1][C-1] + 1;
	
	for(int i=R-2; i>=0; i--)
		cache[i][C-1] = max(cache[i+1][C-1] - p[i][C-1], 1);
	for(int j=C-2; j>=0; j--)
		cache[R-1][j] = max(cache[R-1][j+1] - p[R-1][j], 1);

	for(int i=R-2; i>=0; i--){
		for(int j=C-2; j>=0; j--){
			int tmp = min(cache[i+1][j], cache[i][j+1]);
			cache[i][j] = max(tmp-p[i][j], 1);
		}
	}
	return cache[0][0];
}

int main(){
	int points[R][C] = { {-2,-3,3},
                      {-5,-10,1},
                      {10,30,-5}
                    };
    cout <<"Minimum Initial Points Required: "<<minInitialPoints(points);
}
