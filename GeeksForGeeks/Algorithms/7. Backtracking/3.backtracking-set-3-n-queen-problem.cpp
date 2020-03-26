// http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem

#include <iostream>
#include <cstdio>
using namespace std;

void printArray(int **a, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
}

bool isSafe(int x, int y, int **arr, int N){
	if(x<0 || x>=N || y<0 || y>=N)
		return false;
	int i, j;
	/* Check this row on left side */
	for(i=0; i<N; i++){
		if(arr[x][i])
			return false;
	}
	
	/* Check upper diagonal on left side */
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if(arr[i][j])
            return false;
    }

    /* Check lower diagonal on left side */
    for (i = x, j = y; j >= 0 && i < N; i++, j--){
        if(arr[i][j])
            return false;
    }
    return true;
}

bool solve(int y, int **arr, int N){
	if(y >= N)
		return true;
	for(int x=0; x<N; x++){
		if(isSafe(x, y, arr, N)){
			arr[x][y] = 1;
			if(solve(y+1, arr, N))
				return true;
			arr[x][y] = 0;
		}
	}
	return false;
}

void solveNQ(int N){
	int **arr;
	arr = new int*[N];
	for(int i=0; i<N; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++){
			arr[i][j] = 0;
		}
	}
	solve(0, arr, N);
	printArray(arr, N);
}

int main(){
	int N = 10;
	solveNQ(N);
	return 0;
}

