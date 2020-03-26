// http://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x

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

void fillOX(char **a, int startR, int endR, int startC, int endC, char t){
	if(startR > endR || startC > endC)
		return;
	for(int i=startR; i<=endR; i++){
		a[i][startC] = a[i][endC] = t;
	}
	for(int i=startC; i<=endC; i++){
		a[startR][i] = a[endR][i] = t;
	}
	if(t == 'x')
		fillOX(a, startR+1, endR-1, startC+1, endC-1, 'o');
	else
		fillOX(a, startR+1, endR-1, startC+1, endC-1, 'x');
}

int main(){
	char **arr;
	arr = new char*[5];
	for(int i=0; i<5; i++)
		arr[i] = new char[6];
	puts("Output for m = 5, n = 6");
    fillOX(arr, 0, 4, 0, 5, 'x');
    printMatrix(arr, 5, 6);

    puts("\nOutput for m = 4, n = 4");
    fillOX(arr, 0, 4-1, 0, 4-1, 'x');
	printMatrix(arr, 4, 4);
	
    puts("\nOutput for m = 3, n = 4");
    fillOX(arr, 0, 3-1, 0, 4-1, 'x');
    printMatrix(arr, 3, 4);
	return 0;
}

