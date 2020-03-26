// http://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle

#include <iostream>
#include <cstring>
using namespace std;

bool solve(int **arr, int *res, bool *visit, int V, int len, int node){
	if(len==V){
		if(arr[res[len-1]][res[0]] == 1)
			return true;
		return false;
	}
	for(int i=0; i<V; i++){
		if(visit[i] == false && arr[node][i]){
			visit[i] = true;
			res[len] = i;
			if(solve(arr, res, visit, V, len+1, i))
				return true;
			res[len] = -1;
			visit[i] = false;
		}
	}
	return false;
}

void hamCycle(int **arr, int V){
	int res[V];
	bool visit[V];
	memset(res, -1, sizeof(res));
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	res[0] = 0;
	if(solve(arr, res, visit, V, 1, 0)){
		for(int i=0; i<V; i++){
			cout<<"-->"<<res[i];
		}

	}
	else {
		cout<<"Not exist";
	}
	cout<<'\n';
}

int main(){
	 /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
	int V = 5;
   bool graph1[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
	int **arr = new int*[V];
	for(int i=0; i<V; i++){
		arr[i] = new int[V];
		for(int j=0; j<V; j++)
			arr[i][j] = graph1[i][j];
	}

    // Print the solution
    hamCycle(arr, V);

   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			arr[i][j] = graph2[i][j];
	}

    // Print the solution
    hamCycle(arr, V);
	return 0;
}
