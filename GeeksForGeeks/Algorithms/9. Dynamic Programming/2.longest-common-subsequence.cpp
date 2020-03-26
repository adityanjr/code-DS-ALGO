// http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence

#include <iostream>
#include <cstring>
using namespace std;

int lcs(char *X, char *Y, int m, int n){
    int cache[m+1][n+1];
    memset(cache, 0, sizeof(int)*(m+1)*(n+1));
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                cache[i][j] = 0;
            else if(X[i-1] == Y[j-1]){
                cache[i][j] = cache[i-1][j-1] + 1;
            }
            else {
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
            }
        }
    }
    return cache[m][n];
}

int lcsRec(char *X, char *Y, int m, int n, int **cache){
    if(cache[m][n] != -1){
        return cache[m][n];
    }
    if(X[m-1] == Y[n-1]){
        cache[m][n] = 1 + lcsRec(X, Y, m-1, n-1, cache);
    }
    else {
        cache[m][n] = max(lcsRec(X, Y, m-1, n, cache), lcsRec(X, Y, m, n-1, cache));
    }
    return cache[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    int **cache;
    cache = new int*[m+1];
    for(int i=0; i<m+1; i++){
        cache[i] = new int[n];
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                cache[i][j] = 0;
            else
                cache[i][j] = -1;
        }
    }
    printf("Length of LCS is %d\n", lcsRec( X, Y, m, n, cache) );
	return 0;
}


