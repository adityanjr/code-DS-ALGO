// http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times

#include <iostream>
#include "array.h"

int getOddOccurrence(int *a, int n){
	int res = 0;
	for(int i=0; i<n; i++){
		res = res^a[i];
	}
	return res;
}

int main(){
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOddOccurrence(ar, n));
     return 0;
}
