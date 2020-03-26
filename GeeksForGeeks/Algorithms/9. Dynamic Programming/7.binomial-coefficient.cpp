// http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient

#include <iostream>
using namespace std;

int binomialCoeff(int n, int k, int **C){
    if(C[k][n])
        return C[k][n];
    C[k][n] = binomialCoeff(n-1, k-1, C) + binomialCoeff(n-1, k, C);
    return C[k][n];
}

int binomialCoeff1(int n, int k){
	int cache[k+1];
	int i, j, res;
	C[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=min(i, k); j>0; j--){
			C[j] = C[j] + C[j-1];
		}
	}
	res = C[k];
	free(C);
	return res;
}

int main() {
    int n = 5, k = 2;
    int **C = new int*[k+1];
    for(int i=0; i<k+1; i++){
        C[i] = new int[n+1];
        for(int j=0; j<n+1; j++)
            if(j == i || i==0)
                C[i][j] = 1;
            else
                C[i][j] = 0;
    }
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k, C) );
    cout<<'\n';
    for(int i=0; i<k+1; i++){
        for(int j=0; j<n+1; j++)
            cout<<C[i][j]<<" ";
        cout<<'\n';
    }
	return 0;
}


