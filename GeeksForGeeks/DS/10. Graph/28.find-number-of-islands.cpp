// http://www.geeksforgeeks.org/find-number-of-islands

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define N 5

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(int i, int j){
	if(i<0 || i>=N || j<0 || j>=N)
		return false;
	return true;
}

void DFS(int i, int j, bool M[][N], bool visit[N][N]){
	visit[i][j] = 1;
	for(int k=0; k<8; k++){
		int idx = i+row[k];
		int jdx = j+col[k];
		if(isSafe(idx, jdx) && !visit[idx][jdx] && M[idx][jdx])
			DFS(idx, jdx, M, visit);
	}
}

int countIslands(bool M[][N]){
	bool visit[N][N];
	memset(visit, false, sizeof(bool)*N*N);
	int count=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			if(M[i][j] && visit[i][j] == false){
				count++;
				DFS(i, j, M, visit);
		}
	}
	return count;
}

int main(){
	bool M[][N]= {  {1, 1, 0, 0, 0},
        			{0, 1, 0, 0, 1},
        			{1, 0, 0, 1, 1},
        			{0, 0, 0, 0, 0},
        			{1, 0, 1, 0, 1}
    };

    printf("Number of islands is: %d\n", countIslands(M));

	return 0;
}

