// http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

#include <iostream>
using namespace std;

int knapSack(int W, int *wt, int *val, int n, int **cache){
    if(W == 0|| n==0)
        return 0;
    cache[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1, cache), knapSack(W, wt, val, n-1, cache));
    return cache[n][W];
}

int knapSackIter(int W, int *wt, int *val, int n, int **cache){
    int w = 0;
    for(int i=0; i<=n; i++){
        for(w=0; w<=W; w++){
            if(i==0 || w==0)
                cache[i][w] = 0;
            else if(wt[i-1] <= w){
                cache[i][w] = max(cache[i-1][w], cache[i-1][w-wt[i-1]] + val[i-1]);
            }
            else
                cache[i][w] = cache[i-1][w];
        }
    }
    return cache[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);

    int **cache = new int*[n+1];
    for(int i=0; i<n+1; i++){
        cache[i] = new int[W+1];
        for(int j=0; j<W+1; j++)
            cache[i][j] = 0;
    }

    //printf("%d", knapSack(W, wt, val, n, cache));
    cout<<knapSackIter(W, wt, val, n, cache);
	return 0;
}


