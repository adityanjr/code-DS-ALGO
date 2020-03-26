// http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication

#include <iostream>
using namespace std;

int MatrixChainOrder(int *arr, int n){
    int cache[n][n];
    for(int i=0; i<n; i++)
        cache[i][i] = 0;
    int j, q;
    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            j = i+L-1;
            cache[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                q = cache[i][k] + cache[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q < cache[i][j])
                    cache[i][j] = q;
            }
        }
    }
    return cache[1][n-1];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, size));
	return 0;
}
