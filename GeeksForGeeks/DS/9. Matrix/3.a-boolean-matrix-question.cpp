// http://www.geeksforgeeks.org/a-boolean-matrix-question

#include <iostream>
#include <cstdio>
using namespace std;

void printMatrix(bool **arr, int R, int C){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
}

void modifyMat(bool **a, int R, int C){
	int i=0, j=0;
	bool firstrow = false, firstcol = false;
	for(; j<C; j++){
		if(a[i][j]){
			firstrow = true;
			break;
		}
	}
	i = 0; j=0;
	for(; i<R; i++){
		if(a[i][j]){
			firstcol = true;
			break;
		}
	}
	i=1; j=1;
	for(; i<R; i++){
		for(; j<C; j++){
			if(a[i][j]){
				a[0][j] = 1;
				a[i][0] = 1;
			}
		}
	}
	for(i=1; i<R; i++){
		for(j=1; j<C; j++){
			if(a[0][j] || a[i][0]){
				cout<<i<<" "<<j<<'\n';
				a[i][j] = 1;
			}
		}
	}
	if(firstrow){
		i=0; j=0;
		for(; j<C; j++)
			a[i][j] = 1;
	}
	if(firstcol){
		i=0; j=0;
		for(; i<R; i++)
			a[i][j] = 1;
	}
}

int main(){
	int R = 3, C = 4;
	bool mat[3][4] = { {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };

	bool **arr;
	arr = new bool*[R];
	for(int i=0; i<R; i++){
		arr[i] = new bool[C];
		for(int j=0; j<C; j++)
			arr[i][j] = mat[i][j];
	}

    printf("Input Matrix \n");
    printMatrix(arr, R, C);

    modifyMat(arr, R, C);

    printf("Matrix after modification \n");
    printMatrix(arr, R, C);

	getchar();
}

