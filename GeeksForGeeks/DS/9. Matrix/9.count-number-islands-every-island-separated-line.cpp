// http://www.geeksforgeeks.org/count-number-islands-every-island-separated-line

#include <iostream>
using namespace std;

int countIslands(int **arr, int R, int C){
	int count = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] == 'X'){
				if((i==0 || arr[i-1][j] == 'O') && (j==0 || arr[i][j-1] == 'O'))
					count++;
			}
		}
	}
	return count;
}

int main(){
	int M=6, N=3;
	 int mat[6][3] =  {{'O', 'O', 'O'},
                      {'X', 'X', 'O'},
                      {'X', 'X', 'X'},
                      {'O', 'O', 'X'},
                      {'O', 'O', 'X'},
                      {'X', 'X', 'O'}
                    };
    int **arr;
	arr = new int*[M];
	for(int i=0; i<M; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++)
			arr[i][j] = mat[i][j];
	}
    cout << "Number of rectangular islands is "<< countIslands(arr, M, N);
	return 0;
}

