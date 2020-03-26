// http://www.geeksforgeeks.org/backtracking-set-7-suduku

#include <iostream>
#include <cstdio>
using namespace std;

void printGrid(int **arr, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
}

bool isSafe(int **arr, int N, int x, int y, int data){
	for(int i=0; i<N; i++){
		if(arr[x][i] == data)
			return false;
		if(arr[i][y] == data)
			return false;
	}
	int row = 3*int(x/3);
	int col = 3*int(y/3);
	for(int i=row; i<row + 3; i++){
		for(int j=col; j<col+3; j++){
			if(arr[i][j] == data)
				return false;
		}
	}
	return true;
}

bool solve(int **arr, int N, int x, int y){
	if(x==N && y==0){
		return true;
	}
	if(y == N){
		return solve(arr, N, x+1, 0);
	}
	if(arr[x][y] != 0){
		if(y<N-1)
			return solve(arr, N, x, y+1);
		return solve(arr, N, x+1, 0);
	}
	for(int i=1; i<10; i++){
		if(isSafe(arr, N, x, y, i)){
			arr[x][y] = i;
			if(solve(arr, N, x, y+1))
				return true;
			arr[x][y] = 0;
		}
	}
	return false;
}

bool SolveSudoku(int **arr, int N){
	return solve(arr, N, 0, 0);
}

int main(){
	int N = 9;
	int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 0, 0, 0, 3, 0, 0}};
	int **arr;
	arr =  new int*[N];
	for(int i=0; i<N; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++)
			arr[i][j] = grid[i][j];
	}
	
    if (SolveSudoku(arr, N) == true)
          printGrid(arr, N);
    else
         printf("No solution exists");
	return 0;
}

