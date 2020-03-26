// http://www.geeksforgeeks.org/write-a-program-to-reverse-an-array/

#include <iostream>
#include "array.h"

void reverseArray(int *arr, int start, int end){
	if(start >= end)
		return;
	swap(&arr[start], &arr[end]);
	reverseArray(arr, start+1, end-1);
}

int main(){
  int arr[] = {1, 2, 3, 4, 5};
  printArray(arr, 5);
  reverseArray(arr, 0, 4);
  printf("Reversed array is \n");
  printArray(arr, 5);
  return 0;
}