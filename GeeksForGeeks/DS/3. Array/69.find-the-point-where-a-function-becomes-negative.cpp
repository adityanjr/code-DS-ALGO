// http://www.geeksforgeeks.org/find-the-point-where-a-function-becomes-negative/

#include <iostream>
#include "array.h"

int f(int x) { return (x*x - 10*x - 20); }

int binarySearch(int start, int end){
	if(start > end)
		return -1;
	if(end-start+1 == 1){
		if(f(start)>0)
			return start;
		else -1;
	}
	int mid = (start+end)/2;
	if(f(mid) > 0){
		int a = binarySearch(start, mid-1);
		if(a == -1)
			return mid;
		else
		return a;
	}
	return binarySearch(mid+1, end);
}

int findFirstPositive(){
	if(f(0) > 0)
		return 0;
	int i= 1;
	while(f(i) <= 0)
		i *= 2;
	return binarySearch(0, i);
}

int main(){
	printf("The value n where f() becomes positive first is %d", findFirstPositive());
	return 0;
}

