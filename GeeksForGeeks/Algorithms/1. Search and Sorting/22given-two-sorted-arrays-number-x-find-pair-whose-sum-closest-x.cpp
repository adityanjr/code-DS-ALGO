// http://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x

#include <iostream>
#include <climits>
#include <cstdio>
#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void func(int *arr1, int *arr2, int n1, int n2, int x){
	int i=0, j=n2-1;
	int min = INT_MAX;
	int min_i = i;
	int min_j = j;
	while(i < n1 && j >= 0) {
		int diff = abs(arr1[i]+arr2[j]-x);
		if(diff < min) {
			min = diff;
			min_i = i;
			min_j = j;
		}
		if (arr1[i]+arr2[j] < x)
			i++;
		else
			j--;
	}
	cout<<min_i<<" "<<min_j;
}

int main(){
	int arr1[] = {1, 4, 5, 7};
	int arr2[] = {10, 20, 30, 40};
	int x = 50;
	func(arr1, arr2, sizeof(arr1)/sizeof(*arr1), sizeof(arr2)/sizeof(*arr2) , x);	
	return 0;
}