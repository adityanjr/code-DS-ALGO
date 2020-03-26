// http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array

#include <iostream>
#include "array.h"

void printRepeating(int *a, int n){
	int _xor = 0;
	for(int i=0; i<n-2; i++){
		_xor = _xor ^ a[i];
		_xor = _xor ^ (i+1);
	}
	_xor = _xor ^ a[n-1] ^ a[n-2];
	int set_bit = _xor & ~(_xor-1);
	
	int x=0, y=0;
	for(int i=1; i<n-1; i++){
		if(i&set_bit){
			x = x^i;
		}
		else {
			y = y^i;
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]&set_bit){
			x = x^a[i];
		}
		else {
			y = y^a[i];
		}
	}
	cout<<x<<" "<<y;
}

int main(){
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  return 0;
}
