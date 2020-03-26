// http://www.geeksforgeeks.org/leaders-in-an-array/

#include <iostream>
#include "array.h"

void printLeaders(int *a, int n){
	int max = INT_MIN;
	for(int i=n-1; i>=0; i--){
		if(a[i] > max){
			max = a[i];
			cout<<a[i]<<" ";
		}
	}
}

int main(){
  int arr[] = {16, 17, 4, 3, 5, 2};
  printLeaders(arr, 6);
}
