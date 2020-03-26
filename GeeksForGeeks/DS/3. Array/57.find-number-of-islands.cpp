// http://www.geeksforgeeks.org/find-number-of-islands/
/* TO DO*/

#include <iostream>
#include <cstring>
#include "array.h"

#define N 5

int countIslands(int M[][N]){
	bool visited[N][N];
	int count++;
	memset(isVisited, false, sizeof(isVisited));
	for(int i=0; i<N; i++){
		DFS(M, i, visited);
		count++;
	}
}

int main(){
	int M[][N]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(M));
	return 0;
}

