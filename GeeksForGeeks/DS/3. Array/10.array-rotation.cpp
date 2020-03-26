// http://www.geeksforgeeks.org/array-rotation/
//***
// A Juggling Algorithm

#include <iostream>
#include "array.h"


int gcd(int a,int b){
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

// jugling
void leftRotate(int *arr, int k, int n){
	int i, j, d, tmp;
	for(int i=0; i<gcd(n, k); i++){
		tmp = arr[i];
		j = i;
		while(1){
			d = j+k;
			if(d >= n)
				d -=n;
			if(d == i)
				break;
			arr[j] = arr[d];
			j = d;
		}
		arr[j] = tmp;
	}
}

void leftRotateReversal(int *a, int k, int n){
	reverse(a, 0, k-1);
	reverse(a, k, n-1);
	reverse(a, 0, n-1);
}

int main(){
   int arr[] = {1, 2, 3, 4, 5, 6};
   //leftRotate(arr, 4, 6);
   leftRotateReversal(arr, 4, 6);
   printArray(arr, 6);
   return 0;
}
