// http://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

#include <iostream>
using namespace std;

void printMatrix(char **a, int R, int C){
    for(int i=0; i<R; i++){
    	for(int j=0; j<C; j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<'\n';
	}
}

void floodFill(char **arr, int i, int j, int R, int C){
	if(i<0 || i>=R || j<0 || j>=C)
		return;
	if(arr[i][j] == '-'){
		arr[i][j] = 'O';
		floodFill(arr, i+1, j, R, C);
		floodFill(arr, i-1, j, R, C);
		floodFill(arr, i, j+1, R, C);
		floodFill(arr, i, j-1, R, C);
	}
}

void replaceSurrounded(char **arr, int R, int C){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] == 'O')
				arr[i][j] = '-';
		}
	}

	for(int i=0; i<R; i++){
		floodFill(arr, i, 0, R, C);
		floodFill(arr, i, C-1, R, C);
	}
	for(int j=0; j<R; j++){
		floodFill(arr, 0, j, R, C);
		floodFill(arr, R-1, j, R, C);
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] == '-')
				arr[i][j] = 'X';
		}
	}
}

int main(){
	int R = 6, C = 6;
	char mat[6][6] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
    };

	char **arr;
	arr = new char*[R];
	for(int i=0; i<R; i++){
		arr[i] = new char[C];
		for(int j=0; j<C; j++)
			arr[i][j] = mat[i][j];
	}
	printMatrix(arr, R, C);
	cout<<'\n';
    replaceSurrounded(arr, R, C);
	printMatrix(arr, R, C);
	return 0;
}

