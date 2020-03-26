// http://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include <iostream>
#include "array.h"

int median(int arr[], int n) {
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int getMedian(int *a, int *b, int n){
	if (n == 1)
       	return (a[0] + b[0])/2;
    if (n == 2)
       	return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
	int med1 = median(a, n);
	int med2 = median(b, n);
	if(a[med1] == b[med2]) {
		return a[med1];
	}
	else if(a[med1] > b[med2]) {
		if(n%2 == 0) {
			getMedian(a, b+n/2, n/2);
		}
		else {
			getMedian(a, b + n/2, n/2 + 1);
		}
	}
	else {
		if(n%2 == 0) {
			getMedian(a+n/2, b, n/2);
		}
		else {
			getMedian(a+n/2, b, n/2 + 1);
		}
	}
}

int main(){
	int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
      printf("Median is %d", getMedian(ar1, ar2, n1));
    else
     printf("Doesn't work for arrays of unequal size");
	return 0;
}