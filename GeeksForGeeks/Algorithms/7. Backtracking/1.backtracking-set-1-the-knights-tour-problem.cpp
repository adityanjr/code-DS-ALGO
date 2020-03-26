// http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem

#include <iostream>
#include <cstring>
using namespace std;

#define N 8

int moveX[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int moveY[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void printArray(int **a){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<'\n';
	}
}

bool isSafe(int x, int y, int **a){
	if ( x >= 0 && x < N && y >= 0 && y < N && a[x][y] == -1)
        return 1;
    return 0;
}

int solve(int x, int y, int **a, int move){
	if(move == 64){
		printArray(a);
		return true;
	}
	int tmpX, tmpY;
	for(int i=0; i<8; i++){
		tmpX = x + moveX[i];
		tmpY = y + moveY[i];
		if(isSafe(tmpX, tmpY, a)){
			a[tmpX][tmpY] = move;
			if(solve(tmpX, tmpY, a, move+1) == true)
	 			return true;
			a[tmpX][tmpY] = -1;
		}
	}
	return false;
}

void solveKT(int x, int y){
	int **a;
	a = new int*[N];
	for(int i=0; i<N; i++){
		a[i] = new int[N];
		for(int j =0; j<N; j++)
			a[i][j] = -1;
	}
	a[0][0] = 0;
	solve(x, y, a, 1);
}

int main(){
	solveKT(0, 0);
	return 0;
}

