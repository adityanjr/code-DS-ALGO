// http://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

int linearSearch(int *a, int start, int end) {
	if(start > end)
		return -1;
	int mid = (start+end)/2;
	if(mid == a[mid])
		return mid;
	else if(a[mid] > mid)
		return linearSearch(a, start, mid-1);
	return linearSearch(a, mid+1, end);
}

int main(){
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Fixed Point is %d", linearSearch(arr, 0, n-1));
    getchar();
    return 0;
}