// http://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form

#include <iostream>
#include <cstdio>
using namespace std;

void spiralPrint(int **arr, int startR, int endR, int startC, int endC){
	if(startR > endR || startC > endC)
		return;
	int i=startR, j = startC;
	if(startR == endR){
		while(j<=endC){
			cout<<arr[i][j]<<" ";
			j++;
		}
		return;
	}
	if(startC == endC){
		while(i<=endR){
			cout<<arr[i][j]<<" ";
			i++;
		}
		return;
	}
	while(j<endC){
		cout<<arr[i][j]<<" ";
		j++;
	}
	while(i<endR){
		cout<<arr[i][j]<<" ";
		i++;
	}
	while(j > startC){
		cout<<arr[i][j]<<" ";
		j--;
	}
	while(i > startR){
		cout<<arr[i][j]<<" ";
		i--;
	}
	spiralPrint(arr, startR+1, endR-1, startC+1, endC-1);
}

int main(){
	int R = 3, C = 3;
	int a[3][3] = { {1,  2,  3},
        {7,  8,  9},
        {13, 14, 15}
    };
    
	int **arr;
	arr = new int*[R];
	for(int i=0; i<R; i++){
		arr[i] = new int[C];
		for(int j=0; j<C; j++)
			arr[i][j] = a[i][j];
	}

    spiralPrint(arr, 0, R-1, 0, C-1);
	getchar();
}

