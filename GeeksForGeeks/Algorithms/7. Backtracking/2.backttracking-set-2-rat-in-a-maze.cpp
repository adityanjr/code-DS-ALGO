// http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze

#include <iostream>
#include <cstdio>
using namespace std;

int moveX[] = {0, 1};
int moveY[] = {1, 0};

void printArray(int **a, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
	cout<<'\n';
}

bool isSafe(int x, int y, int **a, int N){
	if ( x >= 0 && x < N && y >= 0 && y < N && a[x][y] == 1)
        return 1;
    return 0;
}

bool solve(int x, int y, int **maze, int N, int **res) {
	if(x>=N || y>=N)
		return false;
	if(x == N-1 && y == N-1){
		printArray(res, N);
		return true;
	}
	for(int i=0; i<2; i++){
		int tmpX = x+moveX[i];
		int tmpY = y+moveY[i];
		if(isSafe(tmpX, tmpY, maze, N)){
			res[tmpX][tmpY] = 1;
			if(solve(tmpX, tmpY, maze, N, res))
				return true;
			res[tmpX][tmpY] = 0;
		}
	}
	return false;
}

void solveMaze(int **maze, int **res, int N){
    res[0][0] = 1;
	solve(0, 0, maze, N, res);
}

int main(){
	int N = 4;
	int maze[4][4]  =  {{1, 1, 1, 1},
        				{1, 1, 0, 0},
        				{0, 1, 1, 1},
        				{1, 1, 0, 1}
    };
    int **a, **res;
    a = new int*[N];
    res = new int*[N];
    for(int i=0; i<N; i++){
    	a[i] = new int[N];
    	res[i] = new int [N];
    	for(int j=0; j<N; j++){
			a[i][j] = maze[i][j];
			res[i][j] = 0;
    	}
    }
    solveMaze(a, res, N);
	return 0;
}

