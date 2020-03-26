// http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change

#include <iostream>
using namespace std;

int count(int *arr, int m, int n){
    int **cache = new int*[m];
    for(int i=0; i<m; i++){
        cache[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            if(j==0)
                cache[i][j] = 1;
            else
                cache[i][j] = 0;
        }
    }
    int x=0, y=0;
    for(int i=0; i<m; i++){
        for(int j=1; j<=n; j++){
            // Count of solutions including S[j]
            x = (j-arr[i] >= 0)? cache[i][j-arr[i]] : 0;

            //// Count of solutions excluding S[j]
            y = (i >= 1) ? cache[i-1][j] : 0;
            cache[i][j] = x+y;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<=n; j++){
            cout<<cache[i][j]<<" ";
        }
       cout<<'\n';
    }
    return cache[m-1][n];
}

int main() {
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", count(arr, m, n));
	return 0;
}
