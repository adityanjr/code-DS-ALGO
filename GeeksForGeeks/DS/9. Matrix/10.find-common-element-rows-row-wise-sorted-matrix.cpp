// http://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix

#include <iostream>
using namespace std;

int findCommon(int **a, int R, int C){
	int help[R];
	int max = -1;
	for(int i=0; i<R; i++){
		help[i] = 0;
		if(max < a[i][0])
			max = a[i][0];
	}
	bool done = false;
	while(!done){
		done = true;
		for(int i=0; i<R; i++){
			int j=help[i];
			while(j<C && max > a[i][j]){
				j++;
			}
			help[i] = j;
			if(j<C && max < a[i][j]){
				max = a[i][j];
				done = false;
				break;
			}
		}
	}
	return a[0][help[0]];
}

int main(){
	int M=4, N=5;
	 int mat[4][5] = { {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
	int **arr;
	arr = new int*[M];
	for(int i=0; i<M; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++)
			arr[i][j] = mat[i][j];
	}

  int result = findCommon(arr, M, N);
  if (result == -1)
    printf("No common element");
  else
    printf("Common element is %d", result);
	return 0;
}

