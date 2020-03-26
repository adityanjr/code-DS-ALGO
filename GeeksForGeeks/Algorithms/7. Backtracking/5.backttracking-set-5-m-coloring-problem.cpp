// http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/

#include <iostream>
#include <cstring>
using namespace std;

bool check(int **arr, int *color, int V, int m, int x, int c){
	for(int i=0; i<V; i++){
		if(i != x && arr[x][i] && color[i] == c)
			return false;
	}
	return true;
}

bool solve(int **arr, int *color, int V, int m, int vertices){
	if(vertices == V)
		return true;
	for(int i=0; i<m; i++){
		if(check(arr, color, V, m, vertices, i+1)){
			color[vertices] = i+1;
			if(solve(arr, color, V, m, vertices+1))
				return true;
			color[vertices] = -1;
		}
	}
	return false;
}

void graphColoring(int **arr, int V, int m){
	int color[V];
	memset(color, -1, sizeof(color));
	if(solve(arr, color, V, m, 0)){
		for(int i=0; i<V; i++){
			cout<<i<<"-->"<<color[i]<<'\n';
		}
	}
	else
		cout<<"Not-Possible";
}

int main(){
	/* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int V = 4;
    bool graph[4][4] = {{0, 1, 1, 1},
        				{1, 0, 1, 0},
        				{1, 1, 0, 1},
        				{1, 0, 1, 0},
    };
    int **arr;
    arr = new int*[V];
    for(int i=0; i<V; i++){
		arr[i] = new int[V];
		for(int j=0; j<V; j++)
			arr[i][j] = graph[i][j];
    }
    int m = 3; // Number of colors
    graphColoring (arr, V, m);
	return 0;
}

