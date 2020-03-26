// http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap

#include <iostream>
#include <cmath>
using namespace std;

#define INF 99

int printSolution (int p[], int n){
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}

void solveWordWrap(int *l, int n, int M, int cost){
	int extras[n+1][n+1];
	int lc[n+1][n+1];
	int c[n+1];
	int p[n+1];
	
	for(int i=1; i<=n; i++){
		extras[i][i] = M- l[i-1];
		for(int j=i+1; j<=n; j++){
			extras[i][j] = extras[i][j-1] - l[j-1] - 1;
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(extras[i][j] < 0)
				lc[i][j] = INF;
			else if(j == n && extras[i][j] >= 0)
				lc[i][j] = 0;
			else
				lc[i][j] = extras[i][j]*extras[i][j];
		}
	}
	c[0] = 0;
	for(int j=1; j<=n; j++){
		c[j] = INF;
		for(int i=1; i <= j; i++){
			if(c[i-1] != INF && lc[i][j] != INF && (c[i-1] + lc[i][j] < c[j])){
				c[j] = c[i-1] + lc[i][j];
				p[j] = i;
			}
		}
	}
	for(int i=0; i<=n; i++)
		cout<<p[i]<<" ";
	printSolution(p, n);
}

int main(){
	int l[] = {5, 3, 5, 8, 4, 4, 7};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 15;
    solveWordWrap (l, n, M, 2);
	return 0;
}

