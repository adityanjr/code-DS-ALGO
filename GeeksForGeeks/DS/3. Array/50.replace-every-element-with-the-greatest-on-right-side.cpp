// http://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/

#include <bits/stdc++.h>
#include "array.h"
using namespace std;

void nextGreatest(int *a, int n){
	int m = -1;
	for(int i=n-1; i>=0; i--){
		int tmp = m;
		m = max(m, a[i]);
		a[i] = tmp;
	}
}

int main(){
	int arr[] = {16, 17, 4, 3, 5, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  nextGreatest (arr, size);
  printf ("The modified array is: \n");
  printArray (arr, size);
	return 0;
}

