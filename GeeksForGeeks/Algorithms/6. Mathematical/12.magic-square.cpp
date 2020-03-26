// http://www.geeksforgeeks.org/magic-square

#include <iostream>
#include <cstring>
using namespace std;

void generateSquare(int n){
	int matrix[n][n];
	memset(matrix, 0, sizeof(matrix));
	int i= n/2;
	int j = n-1;
	for(int num=1; num<=n*n;){
		if(i == -1 && j == n){
			j = n-2;
			i = 0;
		}
		else {
			if(i<0)
				i = n-1;
			if(j==n)
				j=0;
		}
		if(matrix[i][j]){
			j -= 2;
			i++;
			continue;
		}
		else{
			matrix[i][j] = num++;
		}
		j++; i--;
	}
	for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main(){
	int n = 9; // Works only when n is odd
    generateSquare (n);
	return 0;
}

