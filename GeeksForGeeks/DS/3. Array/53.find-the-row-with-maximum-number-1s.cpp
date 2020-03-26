// http://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/

#include<iostream>
using namespace std;

#define R 4
#define C 4

int rowWithMax1s(bool mat[R][C]){
	int i = 0;
	int j = C-1;
	int k = C;
	int row = 0;
	while(i<R && j>=0){
		if(mat[i][j]){
			k=j;
			row = i;
			j--;
		}
		else {
			i++;
		}
	}
	return row;
}

int main() {
	bool mat[R][C] = { {0, 0, 0, 1},
        				{0, 0, 1, 1},
        				{0, 1, 1, 1},
        				{1, 1, 1, 1}
    };

    printf("Index of row with maximum 1s is %d \n", rowWithMax1s(mat));
	return 0;
}

