// http://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/

#include <iostream>
#include "array.h"

void printTwoOdd(int *a, int n){
	int x = 0, _x=0;
	for(int i=0; i<n; i++){
		x = x^a[i];
	}
	int rightMost = x & ~(x-1);
	for(int i=0; i<n; i++){
		if(a[i]&rightMost){
			_x = _x^a[i];
		}
	}
	cout<<_x<<" "<<(x^_x);
}

int main(){
  int arr[] = {4, 4, 100, 5000, 4, 4, 4, 4, 100, 100};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printTwoOdd(arr, arr_size);
  getchar();
  return 0;
}
