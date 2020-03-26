// http://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/

#include <iostream>
#include <cstdio>
using namespace std;

/*
If the grid width is odd, then the number of inversions in a solvable situation is even.
If the grid width is even, and the blank is on an even row counting from the bottom (second-last, fourth-last etc), then the number of inversions in a solvable situation is odd.
If the grid width is even, and the blank is on an odd row counting from the bottom (last, third-last, fifth-last etc) then the number of inversions in a solvable situation is even.
*/

int countInversions(int *arr, int n){
	int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
            // Value 0 is used for empty space
            if (arr[j] && arr[i] &&  arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

bool isSolvable(int puzzle[3][3], int n){
	int *arr = (int *)puzzle;
	int res = countInversions(arr, n*n);
	if(res%2 == 0)
		return true;
	return false;
}

int main(){
	int puzzle[3][3] =  {{1, 8, 2},
                      {0, 4, 3},  // Value 0 is used for empty space
                      {7, 6, 5}};
  isSolvable(puzzle, 3)? cout << "Solvable":
                      cout << "Not Solvable";
	return 0;
}

