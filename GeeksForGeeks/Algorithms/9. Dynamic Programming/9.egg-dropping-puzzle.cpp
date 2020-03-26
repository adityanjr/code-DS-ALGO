// http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle

#include <iostream>
using namespace std;

int eggDrop(int n, int k){
    int cache[n+1][k+1];
    int res, i, j, x;
    for(int i=1; i<=n; i++){
        cache[i][1] = 1;
        cache[i][0] = 0;
    }
    for(int i=1; i<=k; i++)
        cache[1][i] = i;

    for(i=2; i<=n; i++){
        for(j=2; j<=k; j++){
            cache[i][j] = INT_MAX;
            for(x = 1; x<=j; x++){
                res = 1 + max(cache[i-1][x-1], cache[i][j-x]);
                if(res < cache[i][j])
                    cache[i][j] = res;
            }
        }
    }
    return cache[n][k];
}

int main() {
    int n = 2, k = 36;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
	return 0;
}


