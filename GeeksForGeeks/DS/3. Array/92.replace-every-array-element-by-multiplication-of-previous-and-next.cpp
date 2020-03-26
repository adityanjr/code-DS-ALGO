// http://geeksquiz.com/replace-every-array-element-by-multiplication-of-previous-and-next/

#include <iostream>
#include "array.h"

void modify(int *a, int n){
	int prev = a[0];
	a[0] = prev*a[1];
	for(int i=1; i<n-1; i++){
		int tmp = prev;
		prev = a[i];
		a[i] = tmp*a[i+1];
	}
	a[n-1] *= prev;
}

int main(){
	int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    modify(arr, n);
    for (int i=0; i<n; i++)
      cout << arr[i] << " ";
	return 0;
}

