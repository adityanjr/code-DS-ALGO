// http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include <iostream>
#include <cstdio>
using namespace std;

void search(int **arr, int n, int x){
	int i=0, j=n-1;
	while(i<n && j>=0){
		if(arr[i][j] == x){
			cout<<i<<" "<<j;
			return;
		}
		if(arr[i][j] > x)
			j--;
		else
			i++;
	}
}

int main(){
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
	int n = 4;
	int **arr;
	arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[4];
		for(int j=0; j<n; j++)
			arr[i][j] = mat[i][j];
	}
  	search(arr, 4, 29);
	getchar();
}

