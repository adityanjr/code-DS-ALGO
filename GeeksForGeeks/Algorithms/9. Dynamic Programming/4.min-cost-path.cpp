// http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include <iostream>
#include <cstdio>
using namespace std;

int recurse(int **arr, int **cache, int m, int n){
    if(m<0 || n<0)
        return INT_MAX;
    if(cache[m][n]){
        return cache[m][n];
    }
    cache[m][n] = min(recurse(arr, cache, m-1, n), min(recurse(arr, cache, m, n-1), recurse(arr, cache, m-1, n-1)))+arr[m][n];
    return cache[m][n];
}

int minCost(int **arr, int m, int n){
    int **cache = new int*[m+1];
    for(int i=0; i<m+1; i++){
        cache[i] = new int[n+1];
        for(int j=0; j<n+1; j++)
           cache[i][j] = 0;
    }
    cache[0][0] = arr[0][0];
    return recurse(arr, cache, m, n);
}

int main() {
    int R = 3, C = 3;
    int cost[3][3] = { {1, 2, 3},
                      {1, 8, 2},
                      {1, 1, 3} };
    int **arr;
    arr = new int*[R];
    for(int i=0; i<R; i++){
        arr[i] = new int[C];
        for(int j=0; j<C; j++)
            arr[i][j] = cost[i][j];
    }
    printf("%d ", minCost(arr, 2, 2));

	return 0;
}


