// http://geeksquiz.com/binary-search/
#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int recursiveBinarySearch(int arr[], int start, int end, int x){
	if (end<start)
		return -1;
	int ind = (start+end)/2;
	if(arr[ind] == x)
		return ind;
	else if(arr[ind] > x)
		return recursiveBinarySearch(arr, start, ind-1, x);
	else
		return recursiveBinarySearch(arr, ind+1, end, x);
}

int iterativeBinarySearch(int arr[], int start, int end, int x) {
	int ind;
	while (end>=start) {
		ind = (start+end)/2;
		if(arr[ind] == x)
			return ind;
		else if(arr[ind] > x)
			end = ind-1;
		else
			start = ind+1;
	}
	return -1;
}

int main(){
	int sortedArr[] = {1, 3, 5, 6, 9, 10, 11, 15, 18, 23, 28, 29, 30, 50, 100};
	cout<<recursiveBinarySearch(sortedArr, 0, sizeof(sortedArr)/sizeof(sortedArr[0]), 22);
	cout<<iterativeBinarySearch(sortedArr, 0, sizeof(sortedArr)/sizeof(sortedArr[0]), 23);
	return 0;
}
/*
Time Complexity:
The time complexity of Binary Search can be written as
T(n) = T(n/2) + c 

The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is \Theta(Logn).

Auxiliary Space: O(1) in case of iterative implementation. In case of recursive implementation, O(Logn) recursion call stack space.

Algorithmic Paradigm: Divide and Conquer


*/