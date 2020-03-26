// http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix

#include <iostream>
#include <cstdio>
using namespace std;

void printMaxSubSquare(int **arr, int R, int C){
	int M = 1;
	for(int i=1; i<R; i++){
		for(int j=1; j<C; j++){
			if(arr[i][j] != 0 && arr[i][j-1] > 0  && arr[i-1][j] > 0)
				arr[i][j] = arr[i-1][j-1]+1;
				M = max(M, arr[i][j]);
		}
	}
	cout<<M;
}

int main(){
	int R = 6, C = 5;
	bool M[6][5] =  {{0, 1, 1, 0, 1},
                   {1, 1, 1, 1, 1},
                   {0, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	int **arr = new int*[R];
	for(int i=0; i<R; i++){
		arr[i] = new int[C];
		for(int j=0; j<C; j++)
			arr[i][j] = M[i][j];
	}
	printMaxSubSquare(arr, R, C);
	return 0;
}

