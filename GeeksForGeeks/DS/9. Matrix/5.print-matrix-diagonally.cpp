// http://www.geeksforgeeks.org/print-matrix-diagonally

#include <iostream>
using namespace std;

void printMatrix(int **a, int R, int C){
    for(int i=0; i<R; i++){
    	for(int j=0; j<C; j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<'\n';
	}
}

void printDiagonalOrder(int **a, int R, int C){
	for(int k=0; k<R-1; k++){
		int i=k;
		int j=0;
		while(i>=0 && j<=k){
			cout<<a[i][j]<<" ";
			i--;
			j++;
		}
		cout<<'\n';
	}
	for(int i=R-1, j=0; i>=0 && j<C; i--, j++){
		cout<<a[i][j]<<" ";
	}
	cout<<'\n';
	for(int k=1; k<R; k++){
		int i=R-1;
		int j=k;
		while(i>=0 && j<C){
			cout<<a[i][j]<<" ";
			i--;
			j++;
		}
		cout<<'\n';
	}
}

int main(){
	int R = 4, C=4;
	int M[4][4] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16},
                      };
    printf ("Given matrix is \n");
    
    int **arr;
    arr = new int*[R];
    for(int i=0; i<R; i++){
    	arr[i] = new int[C];
    	for(int j=0; j<C; j++){
    		arr[i][j] = M[i][j];
    	}
    }
    
    printMatrix(arr, R, C);

    printf ("\nDiagonal printing of matrix is \n");
    printDiagonalOrder(arr, R, C);
	return 0;
}

